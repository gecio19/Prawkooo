#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPixmap>
#include <string>
#include <QMediaPlayer>
#include <QVideoWidget>
#include <QDebug>
#include <QFile>

using namespace std;

QFile file("E:/PrawoJazdy/Prawo_Jazdy/Ciekawostki.txt");
QString line[100];
int line_count = 0;
QString generator;
int Wylosowanalinia;
int licz = 0;














int wynik;
int skrzyzowania;
int A1,A2,A3,B1,B2,B3,C1,C2,C3 = 0;
int loswanie;
int czas;
int poprawna;
int test = 15;

int odp1;
int odp2;
int odpowiedzA;
int odpowiedzB;
int poprawnaOdowiedz;
int pulapunktow;
int Postep = 1;











MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    timer = new QTimer(this);

    ui->horizontalSlider->setVisible(false);
    ui->horizontalSlider->setValue(Postep);

    QPixmap nauka(":/Menu/Nauka.png");
    QPixmap dodatki(":/Menu/dodatki.png");
    QPixmap egzamin(":/Menu/egzamin.png");
    QPixmap skrzyzowania(":/Menu/skrzyzowania.png");
    QPixmap zakoncz(":/Menu/zakoncz.png");
    QPixmap zrodla(":/Menu/zrodla.png");
    QPixmap znak01(":/Nauka/Nauka/01.jpg");
    QPixmap znak02(":/Nauka/Nauka/02.jpg");
    QPixmap znak03(":/Nauka/Nauka/03.jpg");
    QPixmap Ciekawostki(":/Dodatki/Dodatki/Ciekawostki.jpg");
    QPixmap Pomoc(":/Dodatki/Dodatki/Pomoc.jpg");
    QPixmap Pierwsz(":/Dodatki/Dodatki/Pierwsza_Pomoc.jpg");
    QPixmap Boczna(":/Dodatki/Dodatki/istockphoto-163923050-1024x1024.jpg");












    ui->menu_nauka->setIcon(nauka);

    ui->menu_egzamin->setIcon(egzamin);
    ui->menu_skrzyzowania->setIcon(skrzyzowania);
    ui->menu_zakoncz->setIcon(zakoncz);
    ui->menu_zrodla->setIcon(zrodla);
    ui->menu_dodatki->setIcon(dodatki);
    ui->znak_01->setPixmap(znak01);
    ui->znak_02->setPixmap(znak02);
    ui->znak_03->setPixmap(znak03.scaled(700,360));
    ui->Ciekawostki->setIcon(Ciekawostki);
    ui->Pomoc->setIcon(Pomoc);
    ui->pushButton_14->setIcon(Pierwsz);
    ui->pushButton_15->setIcon(Boczna);























}










MainWindow::~MainWindow()
{
    delete ui;
}



void Policzilelini()
{
    line_count = 0;
    file.open(QIODevice::ReadOnly);

    QTextStream in(&file);

    while(!in.atEnd())
    {
       line[line_count] = in.readLine();
       line_count++;
    }

    Wylosowanalinia = rand() %  line_count;
    file.close();

}



void odczyt()
{


    licz = 0;

    if (file.open(QIODevice::ReadOnly))
    {
       QTextStream in(&file);
       while (!in.atEnd())
       {


          QString line = in.readLine();

          if(licz == Wylosowanalinia)
          {
              generator = line;


          }

          licz = licz +1;



       }
       file.close();

        }



}















void MainWindow::myfunction()
{
    test -=1;
    QString t = QString::number(test);
    ui->label_14->setText(t);
    ui->label_14->setAlignment(Qt::AlignCenter);

    if(test == 0)
    {

    timer->stop();
    on_pushButton_22_clicked();
    }





}


void MainWindow::on_menu_zakoncz_clicked()
{
    close();
}


void MainWindow::on_menu_nauka_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_nauka_0_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
    ui->sprawdzone_01->setVisible(false);


}


void MainWindow::on_Tak_01_clicked()
{
    ui->Tak_01->setStyleSheet({"background: green "});
    ui->Nie_01->setStyleSheet({"background: white "});
    wynik = 0;

}


void MainWindow::on_Nie_01_clicked()
{
    ui->Tak_01->setStyleSheet({"background: white "});
    ui->Nie_01->setStyleSheet({"background: green "});
    wynik = 1;

}


void MainWindow::on_pushButton_clicked()
{
    ui->sprawdzone_01->setVisible(true);
    if(wynik == 1)
    {

      ui->sprawdzone_01->setStyleSheet({"background: green "});
      ui->sprawdzone_01->setText("Odpowiedź prawidłowa");
      ui->label_2->setText("1/1");
      ui->label_2->setAlignment(Qt::AlignCenter);
      Postep += 25;
      ui->horizontalSlider->setValue(Postep);




    }
    else if(wynik == 0){
        ui->sprawdzone_01->setStyleSheet({"background: red "});
        ui->sprawdzone_01->setText("Odpowiedź błędna");



    }




}


void MainWindow::on_pushButton_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_4_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_nauka_1_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
    wynik = 3;
    ui->sprawdzone_02->setVisible(false);
}


void MainWindow::on_Tak_2_clicked()
{
    ui->Tak_2->setStyleSheet({"background: green "});
    ui->Nie_2->setStyleSheet({"background: white "});
    wynik = 0;
}


void MainWindow::on_Nie_2_clicked()
{
    ui->Tak_2->setStyleSheet({"background: white "});
    ui->Nie_2->setStyleSheet({"background: green "});
    wynik = 1;


}


void MainWindow::on_pushButton_7_clicked()
{
    ui->sprawdzone_02->setVisible(true);
    if(wynik == 1)
    {

      ui->sprawdzone_02->setStyleSheet({"background: green "});
      ui->sprawdzone_02->setText("Odpowiedź prawidłowa");
      ui->label_4->setText("1/2");
      ui->label_4->setAlignment(Qt::AlignCenter);
      Postep += 25;
      ui->horizontalSlider->setValue(Postep);





    }
    else if(wynik == 0){
        ui->sprawdzone_02->setStyleSheet({"background: red "});
        ui->sprawdzone_02->setText("Odpowiedź błędna");



    }





}


void MainWindow::on_pushButton_5_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);

}


void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_6_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
     ui->sprawdzone_3->setVisible(false);
     wynik = 0;
}


void MainWindow::on_Tak_3_clicked()
{
    ui->Tak_3->setStyleSheet({"background: green "});
    ui->Nie_03->setStyleSheet({"background: white "});
    wynik = 1;

}


void MainWindow::on_Nie_3_clicked()
{
    ui->Nie_3->setStyleSheet({"background: green "});
    ui->Tak_4->setStyleSheet({"background: white "});
    wynik = 0;
}


void MainWindow::on_Nie_03_clicked()
{
    ui->Tak_3->setStyleSheet({"background: white "});
    ui->Nie_03->setStyleSheet({"background: green "});
    wynik = 0;


}


void MainWindow::on_pushButton_11_clicked()
{
    ui->sprawdzone_3->setVisible(true);
    if(wynik == 1)
    {

      ui->sprawdzone_3->setStyleSheet({"background: green "});
      ui->sprawdzone_3->setText("Odpowiedź prawidłowa");
      ui->label_4->setText("2/2");
      ui->label_4->setAlignment(Qt::AlignCenter);
      Postep += 25;
      ui->horizontalSlider->setValue(Postep);





    }
    else if(wynik == 0){
        ui->sprawdzone_3->setStyleSheet({"background: red "});
        ui->sprawdzone_3->setText("Odpowiedź błędna");



    }


}


void MainWindow::on_pushButton_9_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_12_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_pushButton_13_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_menu_skrzyzowania_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
    ui->sprawdzone_6->setVisible(false);
    QPixmap skrzyzowanie0(":/Skrzyzowania/skrzyzowania/skrzyzowanie1.png");
    ui->znak_5->setPixmap(skrzyzowanie0.scaled(700,360));
    ui->label_21->setText("Podaj kolejność przejazdu");
}


void MainWindow::on_skrzyzowania_A1_clicked()
{

    ui->skrzyzowania_A1->setStyleSheet({"background: green "});
    ui->Skrzyzowania_A2->setStyleSheet({"background: white "});
    ui->Skrzyzowania_A3->setStyleSheet({"background: white "});
    ui->Skrzyzowania_B1->setStyleSheet({"background: white "});
    ui->Skrzyzowania_C1->setStyleSheet({"background: white "});
    A1 = 1;
    A2 = 0;
    A3 = 0;
    B1 = 0;
    C1 = 0;

}


void MainWindow::on_Skrzyzowania_A2_clicked()
{
    ui->skrzyzowania_A1->setStyleSheet({"background: white "});
    ui->Skrzyzowania_A2->setStyleSheet({"background: green "});
    ui->Skrzyzowania_A3->setStyleSheet({"background: white "});
    ui->Skrzyzowania_B2->setStyleSheet({"background: white "});
    ui->Skrzyzowania_C2->setStyleSheet({"background: white "});
    A2 = 1;
    A1 = 0;
    A3 = 0;
    B2 = 0;
    C2 = 0;


}


void MainWindow::on_Skrzyzowania_A3_clicked()
{
    ui->skrzyzowania_A1->setStyleSheet({"background: white "});
    ui->Skrzyzowania_A2->setStyleSheet({"background: white "});
    ui->Skrzyzowania_A3->setStyleSheet({"background: green "});
    ui->Skrzyzowania_B3->setStyleSheet({"background: white "});
    ui->Skrzyzowania_C3->setStyleSheet({"background: white "});
    A3 = 1;
    A2 = 0;
    A1 = 0;
    B3 = 0;
    C3 = 0;

}


void MainWindow::on_Skrzyzowania_B1_clicked()
{
    ui->Skrzyzowania_B1->setStyleSheet({"background: green "});
    ui->Skrzyzowania_B2->setStyleSheet({"background: white "});
    ui->Skrzyzowania_B3->setStyleSheet({"background: white "});
    ui->skrzyzowania_A1->setStyleSheet({"background: white "});
    ui->Skrzyzowania_C1->setStyleSheet({"background: white "});
    B1 = 1;
    B2 = 0;
    B3 = 0 ;
    A1 = 0;
    C1 = 0;

}


void MainWindow::on_Skrzyzowania_B2_clicked()
{
    ui->Skrzyzowania_B1->setStyleSheet({"background: white "});
    ui->Skrzyzowania_B2->setStyleSheet({"background: green "});
    ui->Skrzyzowania_B3->setStyleSheet({"background: white "});
    ui->Skrzyzowania_A2->setStyleSheet({"background: white "});
    ui->Skrzyzowania_C2->setStyleSheet({"background: white "});
    B2 = 1;
    C2 = 0;
    A2 = 0;
    B1 = 0;
    B3 = 0;

}


void MainWindow::on_Skrzyzowania_B3_clicked()
{
    ui->Skrzyzowania_B1->setStyleSheet({"background: white "});
    ui->Skrzyzowania_B2->setStyleSheet({"background: white "});
    ui->Skrzyzowania_B3->setStyleSheet({"background: green "});
    ui->Skrzyzowania_A3->setStyleSheet({"background: white "});
    ui->Skrzyzowania_C3->setStyleSheet({"background: white "});
    B3 = 1;
    B2 =0;
    B1 = 0;
    A3 = 0;
    C3 = 0;

}


void MainWindow::on_Skrzyzowania_C1_clicked()
{
    ui->Skrzyzowania_C1->setStyleSheet({"background: green "});
    ui->Skrzyzowania_C2->setStyleSheet({"background: white "});
    ui->Skrzyzowania_C3->setStyleSheet({"background: white "});
    ui->skrzyzowania_A1->setStyleSheet({"background: white "});
    ui->Skrzyzowania_B1->setStyleSheet({"background: white "});
    C1 = 1;
    C2 =0;
    C3 = 0;
    B1 = 0;
    A1 = 0;

}


void MainWindow::on_Skrzyzowania_C2_clicked()
{
    ui->Skrzyzowania_C1->setStyleSheet({"background: white "});
    ui->Skrzyzowania_C2->setStyleSheet({"background: green "});
    ui->Skrzyzowania_C3->setStyleSheet({"background: white "});
    ui->Skrzyzowania_A2->setStyleSheet({"background: white "});
    ui->Skrzyzowania_B2->setStyleSheet({"background: white "});
    C2 = 1;
    C1= 0;
    C3 =0;
    B2 = 0;
    A2 = 0;

}


void MainWindow::on_Skrzyzowania_C3_clicked()
{
    ui->Skrzyzowania_C1->setStyleSheet({"background: white "});
    ui->Skrzyzowania_C2->setStyleSheet({"background: white "});
    ui->Skrzyzowania_C3->setStyleSheet({"background: green "});
    ui->Skrzyzowania_B3->setStyleSheet({"background: white "});
    ui->Skrzyzowania_A3->setStyleSheet({"background: white "});
    C3 = 1;
    C2 = 0;
    C1 = 0;
    B3 = 0;
    A3 = 0;


}




void MainWindow::on_pushButton_29_clicked()
{
ui->sprawdzone_6->setVisible(true);
    if(A3 == 1 && B2 == 1 && C1 ==1 )
    {
        ui->sprawdzone_6->setStyleSheet({"background: green "});
        ui->sprawdzone_6->setText("Odpowiedź prawidłowa");

    }else
    {
        ui->sprawdzone_6->setStyleSheet({"background: red "});
        ui->sprawdzone_6->setText("Odpowiedź błędna");


    }






}


void MainWindow::on_pushButton_27_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_menu_dodatki_clicked()
{
       ui->stackedWidget->setCurrentIndex(6);
}


void MainWindow::on_Ciekawostki_clicked()
{
    ui->stackedWidget->setCurrentIndex(7);

}


void MainWindow::on_Pomoc_clicked()
{
    ui->stackedWidget->setCurrentIndex(8);

}


void MainWindow::on_pushButton_31_clicked()
{
    Policzilelini();
    odczyt();
    ui->label_25->setText(generator);








}


void MainWindow::on_pushButton_32_clicked()
{
 ui->stackedWidget->setCurrentIndex(0);
}




void MainWindow::on_pushButton_14_clicked()
{
    QMediaPlayer* player = new QMediaPlayer;
    QVideoWidget* vw = new QVideoWidget;
    player->setVideoOutput(vw);
        player->setMedia(QUrl("qrc:/Filmy/Dodatki/pomoc/Pomoc.mpg"));

        vw->setGeometry(100,100,300,400);


        vw->show();
        player->play();
        qDebug() << player->state();

}


void MainWindow::on_pushButton_15_clicked()
{
    QMediaPlayer* player = new QMediaPlayer;
    QVideoWidget* vw = new QVideoWidget;
    player->setVideoOutput(vw);
        player->setMedia(QUrl("qrc:/Filmy/Dodatki/pomoc/boczna.mpg"));

        vw->setGeometry(100,100,300,400);


        vw->show();
        player->play();
        qDebug() << player->state();

}


void MainWindow::on_pushButton_16_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_menu_egzamin_clicked()
{
    test = 45;
    pulapunktow = 0;
    QPixmap znak01(":/Nauka/Nauka/01.jpg");
    ui->stackedWidget->setCurrentIndex(9);
    connect(timer,SIGNAL(timeout()),this,SLOT(myfunction()));
    timer->start(1000);
    ui->label_11->setPixmap(znak01);
    ui->label_12->setText("Czy w przedstiawionej sytuacji odległość znaku ostrzegawczego <p> od miejsca niebezpieczeństwa wynosi od 150do 300 metrów?");

    ui->pushButton_19->setVisible(true);
    ui->pushButton_21->setVisible(false);
    ui->pushButton_22->setVisible(false);
    ui->label_13->setVisible(false);
    ui->label_16->setVisible(false);
    ui->label_17->setVisible(false);
    ui->pushButton_23->setVisible(false);

}

















void MainWindow::on_pushButton_17_clicked()
{


    ui->pushButton_17->setStyleSheet({"background: green "});
    ui->pushButton_18->setStyleSheet({"background: white "});
    odpowiedzA = 1;
    odpowiedzB = 0;




}


void MainWindow::on_pushButton_18_clicked()
{
    ui->pushButton_18->setStyleSheet({"background: green "});
    ui->pushButton_17->setStyleSheet({"background: white "});
    odpowiedzA = 0;
    odpowiedzB = 1;







}


void MainWindow::on_pushButton_20_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);


}


void MainWindow::on_pushButton_19_clicked()
{
    QPixmap znak02(":/Nauka/Nauka/02.jpg");


    ui->pushButton_17->setStyleSheet({"background: white "});
    ui->pushButton_18->setStyleSheet({"background: white "});
    ui->label_11->setPixmap(znak02);
    ui->label_12->setText("Czy jadąć wprost na skrzyżowaniu <p> masz obowiązek ustąpić pierwszeństwa pojazdowi nadjeżdającemy z lewej strony ? ");
    ui->label_15->setText("2/3");
    ui->label_15->setAlignment(Qt::AlignCenter);

    if(odpowiedzB == 1)
    {
        pulapunktow += 1;

    }
    ui->pushButton_19->setVisible(false);
    ui->pushButton_21->setVisible(true);

    qDebug() << pulapunktow;

}

void MainWindow::on_pushButton_21_clicked()
{
    QPixmap znak03(":/Nauka/Nauka/03.jpg");
    ui->pushButton_17->setStyleSheet({"background: white "});
    ui->pushButton_18->setStyleSheet({"background: white "});
    ui->label_11->setPixmap(znak03.scaled(611,321));
    ui->label_15->setText("3/3");
    ui->label_15->setAlignment(Qt::AlignCenter);
    ui->label_12->setText("Czy jadąć na tym skrzyżowaniu 50 km/h i mająć niedostateczną widoczność po prawej stronie ,<p> powinieneś na tym skrzyżowaniu   zmniejszyć prędkosć");

    if(odpowiedzB == 1)
    {
        pulapunktow += 1;

    }
    qDebug() << pulapunktow;
    ui->pushButton_21->setVisible(false);
    ui->pushButton_22->setVisible(true);



}


void MainWindow::on_pushButton_22_clicked()
{
    if(odpowiedzA == 1)
    {
    pulapunktow += 1;
    }

    timer->stop();


QString wynik = QString::number(pulapunktow);
ui->pushButton_23->setVisible(true);

    if(pulapunktow == 3)
    {


        ui->label_16->setText(wynik +"/3");
        ui->label_16->setAlignment(Qt::AlignCenter);

    ui->label_13->setVisible(true);
    ui->label_16->setVisible(true);
    Postep += 25;
    ui->horizontalSlider->setValue(Postep);



    }
    else
    {
        ui->label_17->setVisible(true);
        ui->label_16->setText(wynik +"/3");
        ui->label_16->setAlignment(Qt::AlignCenter);
        ui->label_16->setVisible(true);





    }














}


void MainWindow::on_pushButton_23_clicked()
{
    ui->stackedWidget->setCurrentIndex(0);

}


void MainWindow::on_menu_zrodla_clicked()
{
  ui->stackedWidget->setCurrentIndex(10);
}


void MainWindow::on_nauka_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);
    ui->label_18->setText("Czy w przedstawionej sytuacji masz prawo skręcić w lewo?");
    QPixmap Lewo(":/Nauka/Nauka/lewo.jpg");
    ui->znak_2->setPixmap(Lewo.scaled(700,360));
    ui->Tak_4->setStyleSheet({"background: white "});
    ui->Nie_3->setStyleSheet({"background: white "});
    poprawna = 2;
    ui->sprawdzone_2->setVisible(false);





}


void MainWindow::on_nauka_3_clicked()
{
    ui->stackedWidget->setCurrentIndex(11);

    ui->label_18->setText("Czy w tej sytuacji , po wjechaniu za synalizator, masz obowiązek zatrzymać się w miejscu wskazanym znakiem STOP ?");
    QPixmap sygnalizacja(":/Nauka/Nauka/sygnalizacja.png");
    ui->znak_2->setPixmap(sygnalizacja.scaled(700,360));

    ui->Tak_4->setStyleSheet({"background: white "});
    ui->Nie_3->setStyleSheet({"background: white "});
    poprawna = 3;
    ui->sprawdzone_2->setVisible(false);







}


void MainWindow::on_Tak_4_clicked()
{

    ui->Tak_4->setStyleSheet({"background: green "});
    ui->Nie_3->setStyleSheet({"background: white "});
    wynik = 1;

}


void MainWindow::on_pushButton_26_clicked()
{
    ui->sprawdzone_2->setVisible(true);
    if(wynik == 1)
    {

      ui->sprawdzone_2->setStyleSheet({"background: green "});
      ui->sprawdzone_2->setText("Odpowiedź prawidłowa");
      ui->label_4->setText("1/1");
      ui->label_4->setAlignment(Qt::AlignCenter);
      Postep += 15;
      ui->horizontalSlider->setValue(Postep);





    }
    else if(wynik == 0){
        ui->sprawdzone_2->setStyleSheet({"background: red "});
        ui->sprawdzone_2->setText("Odpowiedź błędna");



    }


}


void MainWindow::on_pushButton_24_clicked()
{
    ui->stackedWidget->setCurrentIndex(1);
}


void MainWindow::on_pushButton_25_clicked()
{
ui->stackedWidget->setCurrentIndex(0);
}

