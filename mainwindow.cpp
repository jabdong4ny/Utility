#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "volume.h"
#include "UartDialog.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QWidget *widget = new QWidget;
    setCentralWidget(widget);

    QWidget *topFiller = new QWidget;
    topFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    textEdit = new QTextEdit(this);
    button = new QPushButton(tr("ShoulderTap message"));

    m_process = new QProcess(this);
    m_process->setWorkingDirectory(qApp->applicationDirPath());
    connect(m_process, SIGNAL(readyReadStandardOutput()), this, SLOT(setStdout()) );
    connect(m_process, SIGNAL(stateChanged(QProcess::ProcessState)), this,
            SLOT(setProcessState(QProcess::ProcessState)) );
    connect(m_process , SIGNAL(finished(int,QProcess::ExitStatus)), this,
        SLOT(processFinished(int, QProcess::ExitStatus)));
    textEdit->setReadOnly(true);


    infoLabel = new QLabel(tr("<i>Choose a menu option to "
                            "invoke a context menu</i>"));
    infoLabel->setFrameStyle(QFrame::StyledPanel | QFrame::Sunken);
    infoLabel->setAlignment(Qt::AlignCenter);

    QWidget *bottomFiller = new QWidget;
    bottomFiller->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);

    QVBoxLayout *layout = new QVBoxLayout;
    layout->setMargin(5);
    layout->addWidget(topFiller);
    layout->addWidget(button);
    layout->addWidget(textEdit);
    layout->addWidget(infoLabel);
    layout->addWidget(bottomFiller);
    widget->setLayout(layout);

    createActions();
    createMenus();

    QString message = tr("A context menu is available by right-clicking");
    statusBar()->showMessage(message);

    setWindowTitle(tr("[TBOX] Developer Utility v0.3"));
    setMinimumSize(160, 160);
    resize(480, 320);
}

MainWindow::~MainWindow()
{
    delete ui;
}


#ifndef QT_NO_CONTEXTMENU
void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QMenu menu(this);
    menu.addAction(provisionAct);
    menu.addAction(copyAct);
    menu.exec(event->globalPos());
}
#endif // QT_NO_CONTEXTMENU

void MainWindow::setStdout()
{
    textEdit->append(QString::fromLocal8Bit(m_process->readAllStandardOutput() + m_process->readAllStandardError()));

}

void MainWindow::processFinished(int exitCode, QProcess::ExitStatus exitStatus){
    qDebug() << "exitCode = " << exitCode << " exitStatus = " <<exitStatus ;
}

//bool MainWindow::buttonEvent(QEvent *e){
//    qDebug() << "buttonEvent = " << e ;
//}

//bool MainWindow::event(QEvent *e){
//    qDebug() << "buttonEvent = " << e->type() ;
//}

void MainWindow::setProcessState(QProcess::ProcessState newState){
    qDebug() << "newState = " << newState;
    if(QProcess::NotRunning != m_processState
            &&QProcess::NotRunning == newState){
        QFile textFile (mTmpFileName);
        textFile.remove();
    }
    m_processState = newState;
}

void MainWindow::newFile()
{
    infoLabel->setText(tr("Invoked <b>File|New</b>"));
}

void MainWindow::open()
{
    infoLabel->setText(tr("Invoked <b>File|Open</b>"));
}

void MainWindow::save()
{
    infoLabel->setText(tr("Invoked <b>File|Save</b>"));
}

void MainWindow::print()
{
    infoLabel->setText(tr("Invoked <b>File|Print</b>"));
}

void MainWindow::command(QString comm){
    QString strCommand;
    if(QSysInfo::productType()=="windows")
        strCommand = "cmd /C adb";
    //strCommand += comm;
    qDebug() << "strCommand = " << strCommand;
    if(m_process->startDetached(strCommand)== true){
        qDebug() << "sucess = " << strCommand;
    } else {
        qDebug() << "fail = " << strCommand;
    }
}

void MainWindow::sos()
{

    mCopyFileName = qApp->applicationDirPath()+"/sos.ini";
    mTmpFileName = qApp->applicationDirPath()+"/sos.cmd";

    QFile textFile (mCopyFileName);
    textFile.copy(mTmpFileName);

    QString strCommand;
    if(QSysInfo::productType()=="windows")
        strCommand = "cmd /C ";
    strCommand += "sos.cmd";
    m_process->start(strCommand);
    infoLabel->setText(tr("Invoked <b>PreCondition Setting|SOS</b>"));
}

void MainWindow::acn()
{
    mCopyFileName = qApp->applicationDirPath()+"/acn.ini";
    mTmpFileName = qApp->applicationDirPath()+"/acn.cmd";

    QFile textFile (mCopyFileName);
    textFile.copy(mTmpFileName);

    QString strCommand;
    if(QSysInfo::productType()=="windows")
        strCommand = "cmd /C ";
    strCommand += "acn.cmd";
    m_process->start(strCommand);

    infoLabel->setText(tr("Invoked <b>PreCondition Setting|ACN</b>"));
}

void MainWindow::provision()
{
    mCopyFileName = qApp->applicationDirPath()+"/provision.ini";
    mTmpFileName = qApp->applicationDirPath()+"/provision.cmd";

    QFile textFile (mCopyFileName);
    textFile.copy(mTmpFileName);

    QString strCommand;
    if(QSysInfo::productType()=="windows")
        strCommand = "cmd /C ";
    strCommand += "tsp_provisiong.cmd";
    m_process->start(strCommand);

    infoLabel->setText(tr("Invoked <b>PreCondition Setting|Provisioning</b>"));
}

void MainWindow::svt()
{
    mCopyFileName = qApp->applicationDirPath()+"/svt.ini";
    mTmpFileName = qApp->applicationDirPath()+"/svt.cmd";

    QFile textFile (mCopyFileName);
    textFile.copy(mTmpFileName);

    QString strCommand;
    if(QSysInfo::productType()=="windows")
        strCommand = "cmd /C ";
    strCommand += "svt.cmd";
    m_process->start(strCommand);

    infoLabel->setText(tr("Invoked <b>PreCondition Setting|SVT</b>"));
}

void MainWindow::cust()
{
    mCopyFileName = qApp->applicationDirPath()+"/cust.ini";
    mTmpFileName = qApp->applicationDirPath()+"/cust.cmd";

    QFile textFile (mCopyFileName);
    textFile.copy(mTmpFileName);

    QString strCommand;
    if(QSysInfo::productType()=="windows")
        strCommand = "cmd /C ";
    strCommand += "cust.cmd";
    m_process->start(strCommand);

    infoLabel->setText(tr("Invoked <b>PreCondition Setting|CUST</b>"));
}

void MainWindow::dhc()
{
    mCopyFileName = qApp->applicationDirPath()+"/dhc.ini";
    mTmpFileName = qApp->applicationDirPath()+"/dhc.cmd";

    QFile textFile (mCopyFileName);
    textFile.copy(mTmpFileName);

    QString strCommand;
    if(QSysInfo::productType()=="windows")
        strCommand = "cmd /C ";
    strCommand += "dhc.cmd";
    m_process->start(strCommand);

    infoLabel->setText(tr("Invoked <b>PreCondition Setting|DHC</b>"));
}

void MainWindow::resetSOS()
{

    mTmpFileName = qApp->applicationDirPath()+"/reset.cmd";

    QFile textFile (mTmpFileName);
    if(textFile.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        QTextStream stream(&textFile);
        stream << "adb1 shell sldd am setprop sos prop.sos.activated 0" << endl;
        stream << "adb1 reboot" << endl;
    }

    QString strCommand;
    if(QSysInfo::productType()=="windows")
        strCommand = "cmd /C ";
    strCommand += "reset.cmd";
    m_process->start(strCommand);

    infoLabel->setText(tr("Invoked <b>Reset Command|SOS</b>"));
}

void MainWindow::resetACN()
{

    mTmpFileName = qApp->applicationDirPath()+"/reset.cmd";

    QFile textFile (mTmpFileName);
    if(textFile.open(QIODevice::ReadWrite| QIODevice::Text))
    {
        QTextStream stream(&textFile);
        stream << "adb1 shell sldd am setprop acn prop.acn.activated 0" << endl;
        stream << "adb1 reboot" << endl;
    }

    QString strCommand;
    if(QSysInfo::productType()=="windows")
        strCommand = "cmd /C ";
    strCommand += "reset.cmd";
    m_process->start(strCommand);

    infoLabel->setText(tr("Invoked <b>Reset Command|ACN</b>"));
}

void MainWindow::copy()
{
    infoLabel->setText(tr("Invoked <b>Edit|Copy</b>"));
}

void MainWindow::paste()
{
    infoLabel->setText(tr("Invoked <b>Edit|Paste</b>"));
}

void MainWindow::about()
{
    infoLabel->setText(tr("Invoked <b>Help|Release Note</b>"));

    QString message;
    QFile textFile (qApp->applicationDirPath()+"/release_note.txt");
    if(textFile.open(QIODevice::ReadOnly| QIODevice::Text))
    {
        while (!textFile.atEnd()) {
                  QByteArray line = textFile.readLine();
                  message.append(line);
        }
    } else {
        message ="can't open";
    }
    QMessageBox::about(this, tr("Release Note"), message);

    //diag
    UartDialog *dlg = new UartDialog();
    dlg->setModal(true);
    dlg->show();
}

void MainWindow::clearTextWindow()
{
    textEdit->clear();
}

void MainWindow::shoulderTap(QString AppName)
{
    QString strCommand;
    if(QSysInfo::productType()=="windows")
        strCommand = "cmd /C ";
    strCommand += "adb1 shell sldd sms-manager recvSmsPlainTSP 00 00 ";
    strCommand += AppName;

    m_process->start(strCommand);

    infoLabel->setText(tr("Invoked <b>shoulderTap|Send Msg</b>"));
}

void MainWindow::shoulderTapToACN()
{
    shoulderTap("ACN");
}

void MainWindow::shoulderTapToSOS()
{
    shoulderTap("SOS");
}

void MainWindow::shoulderTapToSVT()
{
    shoulderTap("SVT");
}

void MainWindow::shoulderTapToDHC()
{
    shoulderTap("DHC");
}

void MainWindow::shoulderTapToPRO()
{
    shoulderTap("PRO");
}

void MainWindow::shoulderTapToDAS()
{
    shoulderTap("DAS");
}

void MainWindow::createActions()
{
    newAct = new QAction(tr("&New"), this);
    newAct->setShortcuts(QKeySequence::New);
    newAct->setStatusTip(tr("Create a new file"));
    connect(newAct, &QAction::triggered, this, &MainWindow::newFile);

    openAct = new QAction(tr("&Open..."), this);
    openAct->setShortcuts(QKeySequence::Open);
    openAct->setStatusTip(tr("Open an existing file"));
    connect(openAct, &QAction::triggered, this, &MainWindow::open);

    saveAct = new QAction(tr("&Save"), this);
    saveAct->setShortcuts(QKeySequence::Save);
    saveAct->setStatusTip(tr("Save the document to disk"));
    connect(saveAct, &QAction::triggered, this, &MainWindow::save);

    printAct = new QAction(tr("&Print..."), this);
    printAct->setShortcuts(QKeySequence::Print);
    printAct->setStatusTip(tr("Print the document"));
    connect(printAct, &QAction::triggered, this, &MainWindow::print);

    exitAct = new QAction(tr("E&xit"), this);
    exitAct->setShortcuts(QKeySequence::Quit);
    exitAct->setStatusTip(tr("Exit the application"));
    connect(exitAct, &QAction::triggered, this, &QWidget::close);

    sosAct = new QAction(tr("&SOS"), this);
    //sosAct->setShortcuts(QKeySequence::Undo);
    sosAct->setStatusTip(tr("Run PreCondition setting about SOS"));
    connect(sosAct, &QAction::triggered, this, &MainWindow::sos);

    acnAct = new QAction(tr("&ACN"), this);
    //acnAct->setShortcuts(QKeySequence::Redo);
    acnAct->setStatusTip(tr("Run PreCondition setting about ACN"));
    connect(acnAct, &QAction::triggered, this, &MainWindow::acn);

    svtAct = new QAction(tr("&SVT"), this);
    svtAct->setStatusTip(tr("Run PreCondition setting about SVT"));
    connect(svtAct, &QAction::triggered, this, &MainWindow::svt);

    provisionAct = new QAction(tr("&Provisioning"), this);
    provisionAct->setStatusTip(tr("Run PreCondition setting about Provisioning"));
    connect(provisionAct, &QAction::triggered, this, &MainWindow::provision);

    custAct = new QAction(tr("&CUST"), this);
    custAct->setStatusTip(tr("Run PreCondition setting about CUST"));
    connect(custAct, &QAction::triggered, this, &MainWindow::cust);

    dhcAct = new QAction(tr("&DHC"), this);
    dhcAct->setStatusTip(tr("Run PreCondition setting about DHC"));
    connect(dhcAct, &QAction::triggered, this, &MainWindow::dhc);

    clearAct = new QAction(tr("&Clear Screen"), this);
    clearAct->setStatusTip(tr("Clear Text Edit Screen"));
    connect(clearAct, &QAction::triggered, this, &MainWindow::clearTextWindow);


    sosResetAct = new QAction(tr("&Reset SOS state & Reboot"), this);
    sosResetAct->setStatusTip(tr("SOS state reset and Reboot"));
    connect(sosResetAct, &QAction::triggered, this, &MainWindow::resetSOS);

    acnResetAct = new QAction(tr("&Reset ACN state & Reboot"), this);
    acnResetAct->setStatusTip(tr("ACN state reset and Reboot"));
    connect(acnResetAct, &QAction::triggered, this, &MainWindow::resetACN);

    copyAct = new QAction(tr("&Copy"), this);
    copyAct->setShortcuts(QKeySequence::Copy);
    copyAct->setStatusTip(tr("Copy the current selection's contents to the "
                             "clipboard"));
    connect(copyAct, &QAction::triggered, this, &MainWindow::copy);

    aboutAct = new QAction(tr("&Relase Note"), this);
    aboutAct->setStatusTip(tr("Show the applications Developed history"));
    connect(aboutAct, &QAction::triggered, this, &MainWindow::about);

    //shoulder tap action
    STacnAct = new QAction(tr("&Shoulder Tap to ACN"), this);
    STacnAct->setStatusTip(tr("send to shoulder Tap message to ACN"));
    connect(STacnAct, &QAction::triggered, this, &MainWindow::shoulderTapToACN);

    STsosAct = new QAction(tr("&Shoulder Tap to SOS"), this);
    STsosAct->setStatusTip(tr("send to shoulder Tap message to SOS"));
    connect(STsosAct, &QAction::triggered, this, &MainWindow::shoulderTapToSOS);

    STsvtAct = new QAction(tr("&Shoulder Tap to SVT"), this);
    STsvtAct->setStatusTip(tr("send to shoulder Tap message to SVT"));
    connect(STsvtAct, &QAction::triggered, this, &MainWindow::shoulderTapToSVT);

    STdhcAct = new QAction(tr("&Shoulder Tap to DHC"), this);
    STdhcAct->setStatusTip(tr("send to shoulder Tap message to DHC"));
    connect(STdhcAct, &QAction::triggered, this, &MainWindow::shoulderTapToDHC);

    STproAct = new QAction(tr("&Shoulder Tap to Provisioning"), this);
    STproAct->setStatusTip(tr("send to shoulder Tap message to Provisioning"));
    connect(STproAct, &QAction::triggered, this, &MainWindow::shoulderTapToPRO);

    STdasAct = new QAction(tr("&Shoulder Tap to das"), this);
    STdasAct->setStatusTip(tr("send to shoulder Tap message to das"));
    connect(STdasAct, &QAction::triggered, this, &MainWindow::shoulderTapToDAS);
}

void MainWindow::createMenus()
{
    /*
    fileMenu = menuBar()->addMenu(tr("&File"));
    fileMenu->addAction(newAct);
    fileMenu->addAction(openAct);
    fileMenu->addAction(saveAct);
    fileMenu->addAction(printAct);
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
*/
    settingMenu = menuBar()->addMenu(tr("&PreCondition Setting"));
    settingMenu->addAction(sosAct);
    settingMenu->addAction(acnAct);
    settingMenu->addSeparator();

    settingMenu->addAction(svtAct);
    settingMenu->addAction(provisionAct);
    settingMenu->addAction(custAct);
    settingMenu->addAction(dhcAct);
    //settingMenu->addAction(copyAct);
    settingMenu->addSeparator();
    settingMenu->addAction(clearAct);

    resetMenu = menuBar()->addMenu(tr("&Reset Command"));
    resetMenu->addAction(sosResetAct);
    resetMenu->addAction(acnResetAct);

    shoulderTapMenu = new QMenu();//menuBar()->addMenu(tr("&sss"));//new QMenu(this);//QtGui.QMenu();
    shoulderTapMenu->addAction(STacnAct);
    shoulderTapMenu->addAction(STsosAct);
    shoulderTapMenu->addAction(STsvtAct);
    shoulderTapMenu->addAction(STdhcAct);
    shoulderTapMenu->addAction(STproAct);
    shoulderTapMenu->addAction(STdasAct);
    button->setMenu(shoulderTapMenu);


    helpMenu = menuBar()->addMenu(tr("&Help"));
    helpMenu->addAction(aboutAct);
}
