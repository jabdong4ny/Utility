#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore>
#include <QMainWindow>
#include <QtWidgets>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

protected:
#ifndef QT_NO_CONTEXTMENU
    void contextMenuEvent(QContextMenuEvent *event) override;
#endif // QT_NO_CONTEXTMENU

private slots:
    void setStdout();
    void newFile();
    void open();
    void save();
    void print();

    void copy();
    void paste();
    void about();

    void sos();
    void acn();
    void svt();
    void cust();
    void provision();
    void dhc();
    void clearTextWindow();

    void resetSOS();
    void resetACN();
    void setProcessState(QProcess::ProcessState newState);
    void processFinished(int, QProcess::ExitStatus);
    //virtual bool event(QEvent *e);

    void shoulderTap(QString);
    void shoulderTapToACN();
    void shoulderTapToSOS();
    void shoulderTapToSVT();
    void shoulderTapToDHC();
    void shoulderTapToPRO();
    void shoulderTapToDAS();

private:
    Ui::MainWindow *ui;

    void createActions();
    void createMenus();
    void command(QString comm);

    QProcess *m_process;

    QPushButton *button;

    QTextEdit *textEdit;

    //Menu
    QMenu *fileMenu;
    QMenu *settingMenu;
    QMenu *resetMenu;
    QMenu *helpMenu;
    QMenu *shoulderTapMenu;

    //sample action
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *printAct;
    QAction *exitAct;
    QAction *copyAct;

    //action - pre setting
    QAction *sosAct;
    QAction *acnAct;
    QAction *svtAct;
    QAction *custAct;
    QAction *provisionAct;
    QAction *dhcAct;
    QAction *clearAct;

    //action - reset
    QAction *sosResetAct;
    QAction *acnResetAct;

    //action - release note
    QAction *aboutAct;

    //action - shoulderTap
    QAction *STacnAct;
    QAction *STsosAct;
    QAction *STsvtAct;
    QAction *STdhcAct;
    QAction *STproAct;
    QAction *STdasAct;

    QLabel *infoLabel;
    int m_processState;
    QString mCopyFileName;
    QString mTmpFileName;

};

#endif // MAINWINDOW_H
