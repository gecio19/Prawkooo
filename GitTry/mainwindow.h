#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE



class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
public slots:
    void myfunction();


private slots:



    void on_menu_zakoncz_clicked();

    void on_menu_nauka_clicked();

    void on_nauka_0_clicked();

    void on_Tak_01_clicked();

    void on_Nie_01_clicked();

    void on_pushButton_clicked();

    void on_pushButton_3_clicked();

    void on_pushButton_4_clicked();

    void on_nauka_1_clicked();

    void on_Tak_2_clicked();

    void on_Nie_2_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_5_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_6_clicked();

    void on_Tak_3_clicked();

    void on_Nie_3_clicked();

    void on_Nie_03_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void on_menu_skrzyzowania_clicked();

    void on_skrzyzowania_A1_clicked();

    void on_Skrzyzowania_A2_clicked();

    void on_Skrzyzowania_B1_clicked();

    void on_Skrzyzowania_A3_clicked();

    void on_Skrzyzowania_B2_clicked();

    void on_Skrzyzowania_B3_clicked();

    void on_Skrzyzowania_C1_clicked();

    void on_Skrzyzowania_C2_clicked();

    void on_Skrzyzowania_C3_clicked();

    void on_pushButton_29_clicked();

    void on_pushButton_27_clicked();

    void on_menu_dodatki_clicked();

    void on_Ciekawostki_clicked();

    void on_Pomoc_clicked();

    void on_pushButton_31_clicked();

    void on_pushButton_32_clicked();

    void on_pushButton_14_clicked();

    void on_pushButton_15_clicked();

    void on_pushButton_16_clicked();

    void on_menu_egzamin_clicked();

    void on_pushButton_21_clicked();

    void on_pushButton_17_clicked();

    void on_pushButton_18_clicked();

    void on_pushButton_20_clicked();

    void on_pushButton_19_clicked();

    void on_pushButton_22_clicked();

    void on_pushButton_23_clicked();

    void on_menu_zrodla_clicked();

    void on_nauka_2_clicked();

    void on_nauka_3_clicked();

    void on_Tak_4_clicked();

    void on_pushButton_26_clicked();

    void on_pushButton_24_clicked();

    void on_pushButton_25_clicked();

private:
    Ui::MainWindow *ui;
    QTimer *timer;
};
#endif // MAINWINDOW_H
