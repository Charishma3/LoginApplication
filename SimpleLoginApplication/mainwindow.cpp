#include "mainwindow.h"
#include<QPushButton>
#include<QLabel>
#include<QLineEdit>
#include<QDebug>
#include<QMessageBox>
#include<QVBoxLayout>
#include<QFont>
#include<dialog.h>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
//Image icon for username
       QLabel *lab=new QLabel(this);
       lab->setMinimumSize(70,50);
       lab->move(100,50);
       QPixmap pixx("C:/Users/kumar/Documents/SimpleLoginApplication/Images/username.jpg");
       lab->setPixmap(pixx.scaled(20,20));
//Set image icon in center
        QLabel *mlabel=new QLabel(this);
        mlabel->move(180,25);
        mlabel->setAlignment(Qt::AlignHCenter);
        QPixmap pix("C:/Users/kumar/Documents/SimpleLoginApplication/Images/login.jpg");
        mlabel->setPixmap(pix.scaled(105, 25));
//QLabel for username mainwindow
         QLabel *unLabel=new QLabel("UserName",this);
         unLabel->setMinimumSize(70,50);
         unLabel->move(130,55);
         QPalette l1;
         l1.setColor(QPalette::WindowText,Qt::red);
         unLabel->setPalette(l1);
//QLineEdit for username
          QLineEdit *unLineEdit=new QLineEdit(this);
          unLineEdit->setMinimumSize(200,50);
          unLineEdit->move(220,55);
//set the lineedit border to red color
          unLineEdit->setStyleSheet("border: 2px solid red");
//Image icon for password
          QLabel *labb=new QLabel(this);
          labb->setMinimumSize(200,50);
          labb->move(100,115);
          QPixmap pixxx("C:/Users/kumar/Documents/SimpleLoginApplication/Images/password.png");
          labb->setPixmap(pixxx.scaled(20,20));
//QLabel for password
          QLabel *pwd=new QLabel("Password",this);
          pwd->setMinimumSize(70,50);
          pwd->move(130,115);
          QPalette l2;
          l2.setColor(QPalette::WindowText,Qt::green);
          pwd->setPalette(l2);
//QLineEdit for password
          QLineEdit *pwdLineEdit=new QLineEdit(this);
          pwdLineEdit->setMinimumSize(200,50);
          pwdLineEdit->move(220,115);
          pwdLineEdit->setEchoMode(QLineEdit::Password);
//set the lineedit border to green color
          pwdLineEdit->setStyleSheet("border: 2px solid green");
//QLabel
          QLabel *account=new QLabel("Dont have an account?",this);
          account->setMinimumSize(120,50);
          account->move(140,240);
//QPushButton for signup
          QFont button("Times",10,QFont::Bold);
          QPushButton *button1=new QPushButton("SignUp",this);
          button1->setFont(button);
          button1->move(265,255);
          button1->setStyleSheet("background-color: rgb(102,205,170)");

          connect(button1,&QPushButton::clicked,[=](){
          Dialog *dialog=new Dialog(this);
             int result = dialog->exec();
                if(result == QDialog::Rejected)
                  {
                      close();
                  }
              });
//QPushButton for Login
          QFont buttons("Times",18,QFont::Bold);
          QPushButton *button2=new QPushButton("Login",this);
          button2->setStyleSheet("background-color: rgb(26,122,232)");
          button2->setFont(buttons);
          button2->setMinimumSize(300, 40);
          button2->move(120,180);
          connect(button2,&QPushButton::clicked,[=](){
             QString userName=unLineEdit->text();
             QString password=pwdLineEdit->text();

             if(userName=="Charishma" && password=="cherry")
                  {
                      QMessageBox::information(this, "Login Successfull", "Username and Password are correct");
                  }
                  else
                  {
                      QMessageBox::information(this, "Login Unsuccessful", "Username or password is incorrect");
                  }
              });
          //Hint text
          unLineEdit->setPlaceholderText("username");
          pwdLineEdit->setPlaceholderText("password");
}

MainWindow::~MainWindow()
{
}


