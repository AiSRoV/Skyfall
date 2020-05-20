Федеральное государственное автономное образовательное учреждение высшего образования  

"КРЫМСКИЙ ФЕДЕРАЛЬНЫЙ УНИВЕРСИТЕТ им. В. И. ВЕРНАДСКОГО"  

ФИЗИКО-ТЕХНИЧЕСКИЙ ИНСТИТУТ  

Кафедра компьютерной инженерии и моделирования
<br/></br>


### Отчет по лабораторной работе №8 </br> по дисциплине "Программирование"
<br/>

Студента 1 курса группы ИВТ-б-о-191(1)  
Гринь Татьяны Станиславовны </br>
направления подготовки 09.03.01 " Информатика и вычислительная техника"  
<br/>

<table>
<tr><td>Научный руководитель<br/> старший преподаватель кафедры<br/> компьютерной инженерии и моделирования</td>
<td>(оценка)</td>
<td>Чабанов В.В.</td>
</tr>
</table>
<br/><br/>
​
Симферополь, 2019

__Цель:__ </tr>

__1.__ Познакомиться с Google Test и Google Mock Framework;<br/>
__2.__ Изучить базовые понятия относящийся к тестированию кода;<br/>
__3.__ Научиться тестировать классы в среде разработки Qt Creator.<br/>

Итоговый тестовый проект: 
[Testing Project](https://github.com/Starfall-6969/Skyfall/tree/master/Laba9/testingProject)<br/>
<br/>
__Скриншоты проведенного тестрирования в Qt__<br/>

![](https://raw.githubusercontent.com/Starfall-6969/Skyfall/master/Laba9/photo/%D0%A1%D0%BD%D0%B8%D0%BC%D0%BE%D0%BA.PNG)<br/>
_Рисунок 1. Итог тестирования с ошибкой_<br/>

![ ](https://raw.githubusercontent.com/Starfall-6969/Skyfall/master/Laba9/photo/no.PNG)
<br/>
_Рисунок 2. Итог тестирования в консоли_

<br/>__Код тестирования__:
<br/>
```C++

#ifndef TST_TT1_H
#define TST_TT1_H
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include <lockcontroller.h>
#include <ILatch.h>
#include <IKeypad.h>

using namespace testing;

class MockILatch: public ILatch{
public:
    MOCK_METHOD(bool, isActive, (), (override));
    MOCK_METHOD(DoorStatus, open,(),(override));
    MOCK_METHOD(DoorStatus, close,(), (override));
   MOCK_METHOD(DoorStatus, getDoorStatus,(),(override));
};

class MockIKeypad: public IKeypad{
public:
   MOCK_METHOD (bool, isActive,(),(override));
   MOCK_METHOD (void, wait,(),(override));
   MOCK_METHOD (PasswordResponse, requestPassword,(),(override));
};


TEST(Tests, wait){

    MockILatch latchTest;
    MockIKeypad keypadTest;
    LockController contrl=LockController(&keypadTest, &latchTest);

    EXPECT_CALL(keypadTest, wait())
            .Times(1); //сколько раз вызывается
    contrl.wait();
}


TEST(Tests, isDoorOpen_Close){
    MockILatch latchTest;
    MockIKeypad keypadTest;
    LockController contrl=LockController(&keypadTest, &latchTest);

    EXPECT_CALL(latchTest, getDoorStatus())
            .Times(1) //сколько раз вызывается
            .WillOnce (Return(DoorStatus::CLOSE));

    bool Return=contrl.isDoorOpen();
    EXPECT_FALSE(Return);
}

TEST(Tests, isDoorOpen_Open){
    MockILatch latchTest;
    MockIKeypad keypadTest;
    LockController contrl=LockController(&keypadTest, &latchTest);

    EXPECT_CALL(latchTest, getDoorStatus())
            .Times(1) //сколько раз вызывается
            .WillOnce (Return(DoorStatus::OPEN));

    bool Return=contrl.isDoorOpen();
    EXPECT_TRUE(Return);

}

TEST(Tests,unlockDoor){
    MockILatch latchTest;
    MockIKeypad keypadTest;
    LockController contrl=LockController(&keypadTest, &latchTest);

     EXPECT_CALL(latchTest, open())
            .Times(1);
   DoorStatus Return= contrl.unlockDoor();

   EXPECT_EQ(Return,DoorStatus::OPEN);

}


TEST(Tests,lockDoor){
    MockILatch latchTest;
    MockIKeypad keypadTest;
    LockController contrl=LockController(&keypadTest, &latchTest);

     EXPECT_CALL(latchTest, close())
            .Times(1)
             .WillOnce(Return(DoorStatus::CLOSE));

     DoorStatus Return= contrl.lockDoor();
   EXPECT_EQ(Return,DoorStatus::CLOSE);

}

TEST(Tests,hardWareCheck){
    MockILatch latchTest;
    MockIKeypad keypadTest;
    LockController contrl=LockController(&keypadTest, &latchTest);

    EXPECT_CALL(latchTest, isActive())
           .Times(1)
      .WillOnce(Return(1));
    EXPECT_CALL(keypadTest, isActive())
           .Times(1)
     .WillOnce(Return(1));

HardWareStatus Return=contrl.hardWareCheck();
    EXPECT_EQ(Return,HardWareStatus::OK);
}

TEST(Tests,hardWareCheck_n){
    MockILatch latchTest;
    MockIKeypad keypadTest;
    LockController contrl=LockController(nullptr, &latchTest);

    EXPECT_CALL(latchTest, isActive())

            .Times(AtLeast(0))
      .WillOnce(Return(1));
    EXPECT_CALL(keypadTest, isActive())
          .Times(AtLeast(0))
     .WillOnce(Return(1));

    HardWareStatus Return=contrl.hardWareCheck();
        EXPECT_EQ(Return,HardWareStatus::ERROR);

}

TEST(Tests,hardWareCheck_L){
    MockILatch latchTest;
    MockIKeypad keypadTest;
    LockController contrl=LockController(&keypadTest, &latchTest);

    EXPECT_CALL(latchTest, isActive())
            .Times(AtLeast(0))
      .WillOnce(Return(0));
    EXPECT_CALL(keypadTest, isActive())
          .Times(AtLeast(0))
     .WillOnce(Return(1));

    HardWareStatus Return=contrl.hardWareCheck();
        EXPECT_EQ(Return,HardWareStatus::ERROR);

}

TEST(Tests,isCorrectPassword){
    MockILatch latchTest;
    MockIKeypad keypadTest;
    LockController contrl=LockController(&keypadTest, &latchTest);

    PasswordResponse passResp{PasswordResponse::Status::OK,"0000"};

    EXPECT_CALL(keypadTest, requestPassword())
            .Times(1)
            .WillOnce(Return(passResp));

    bool Return=contrl.isCorrectPassword();
     EXPECT_TRUE(Return);
}

TEST(Tests,isCorrectPassword_No){
    MockILatch latchTest;
    MockIKeypad keypadTest;
    LockController contrl=LockController(&keypadTest, &latchTest);

    PasswordResponse passResp{PasswordResponse::Status::OK,"0100"};

    EXPECT_CALL(keypadTest, requestPassword())
            .Times(1)
            .WillOnce(Return(passResp));

    bool Return=contrl.isCorrectPassword();
     EXPECT_FALSE(Return);
}


TEST(Tests,isCorrectPassword_New){
    MockILatch latchTest;
    MockIKeypad keypadTest;
    LockController contrl=LockController(&keypadTest, &latchTest);

    PasswordResponse oldPass{PasswordResponse::Status::OK,"0000"};
 PasswordResponse newPass{PasswordResponse::Status::OK,"9876"};

    EXPECT_CALL(keypadTest, requestPassword())
            .Times(2)
            .WillOnce(Return(oldPass))
            .WillOnce(Return(newPass));
            contrl.resetPassword();

     EXPECT_CALL(keypadTest, requestPassword())
             .Times(1)
             .WillOnce(Return(newPass));

     bool Return=contrl.isCorrectPassword();
      EXPECT_TRUE(Return);
}


TEST(Tests,isCorrectPassword_res){
    MockILatch latchTest;
    MockIKeypad keypadTest;
    LockController contrl=LockController(&keypadTest, &latchTest);

    PasswordResponse defPass{PasswordResponse::Status::OK,"0000"};
    PasswordResponse oldPass{PasswordResponse::Status::OK,"1234"};
    PasswordResponse newPass{PasswordResponse::Status::OK,"9876"};

    EXPECT_CALL(keypadTest, requestPassword())
            .Times(2)
            .WillOnce(Return(defPass))
            .WillOnce(Return(oldPass));
            contrl.resetPassword();

     EXPECT_CALL(keypadTest, requestPassword())
             .Times(1)
             .WillOnce(Return(oldPass));

     bool Returned=contrl.isCorrectPassword();
      EXPECT_TRUE(Returned);


      EXPECT_CALL(keypadTest, requestPassword())
              .Times(2)
              .WillOnce(Return(oldPass))
              .WillOnce(Return(newPass));
              contrl.resetPassword();

       EXPECT_CALL(keypadTest, requestPassword())
               .Times(1)
               .WillOnce(Return(newPass));

       Returned=contrl.isCorrectPassword();
        EXPECT_TRUE(Returned);
}



#endif // TST_TT1_H

```
<br/>

__Метод с ошибкой:__
<br/>
```C++
DoorStatus LockController::lockDoor()
{
    return latch->open();
}
```
<br/>

__Исправленный метод:__
<br/>
```C++
DoorStatus LockController::lockDoor()
{
    return latch->close();
}
```

__Скришнот тестирования после исправления ошибки__<br/>

![](https://raw.githubusercontent.com/Starfall-6969/Skyfall/master/Laba9/photo/yes.PNG)<br/>
_Рисунок 3. Итог тестирования исправленного кода._
<br/>

_Данная ошибка могла возникнуть из-за того что не было вызова метода `Close`._<br/>


__Вывод:__ <br/>

В ходе выполнения данной лаботаротной работы ознакомилась с _Google Test_ и _Google Mock Framework_, так же были изучены базовые понятия относящиеся к тестировнаию кода и тестирование классов в среде разработки _Qt Creator_.
