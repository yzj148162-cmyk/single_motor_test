/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.8.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDoubleSpinBox>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *rootLayout;
    QHBoxLayout *topLayout;
    QVBoxLayout *leftLayout;
    QGroupBox *motionGroupBox;
    QFormLayout *motionFormLayout;
    QLabel *axisLabel;
    QSpinBox *axisSpin;
    QLabel *modeLabel;
    QComboBox *modeCombo;
    QLabel *deltaAngleLabel;
    QDoubleSpinBox *deltaAngleSpin;
    QLabel *durationLabel;
    QDoubleSpinBox *durationSpin;
    QLabel *systemPlanningPeriodLabel;
    QSpinBox *systemPlanningPeriodMsSpin;
    QLabel *minVelLabel;
    QDoubleSpinBox *minVelSpin;
    QLabel *maxVelLabel;
    QDoubleSpinBox *maxVelSpin;
    QGroupBox *displayGroupBox;
    QFormLayout *displayFormLayout;
    QLabel *uiRefreshLabel;
    QSpinBox *uiRefreshMsSpin;
    QGroupBox *cspRuntimeGroupBox;
    QFormLayout *cspRuntimeFormLayout;
    QLabel *ecatPortLabel;
    QSpinBox *ecatPortSpin;
    QLabel *nodeLabel;
    QSpinBox *nodeSpin;
    QLabel *cspInterpPeriodMsLabel;
    QSpinBox *cspInterpPeriodMsSpin;
    QLabel *cspInterpIndexLabel;
    QSpinBox *cspInterpIndexSpin;
    QGroupBox *advancedGroupBox;
    QFormLayout *advancedFormLayout;
    QLabel *positionUnitLabel;
    QHBoxLayout *positionUnitLayout;
    QRadioButton *degreeUnitRadio;
    QRadioButton *turnUnitRadio;
    QLabel *cspRxpdoPosAddrLabel;
    QSpinBox *cspRxpdoPosAddrSpin;
    QLabel *cspTxpdoStatusAddrLabel;
    QSpinBox *cspTxpdoStatusAddrSpin;
    QLabel *cspTxpdoModeAddrLabel;
    QSpinBox *cspTxpdoModeAddrSpin;
    QLabel *cspTxpdoPosAddrLabel;
    QSpinBox *cspTxpdoPosAddrSpin;
    QVBoxLayout *rightLayout;
    QGroupBox *buttonBox;
    QGridLayout *buttonLayout;
    QPushButton *initCardButton;
    QPushButton *closeCardButton;
    QPushButton *enableAxisButton;
    QPushButton *disableAxisButton;
    QPushButton *readPosButton;
    QPushButton *stopButton;
    QPushButton *startButton;
    QGroupBox *statusBox;
    QFormLayout *statusLayout;
    QLabel *connectionTextLabel;
    QLabel *connectionLabel;
    QLabel *positionTextLabel;
    QLabel *positionLabel;
    QLabel *stateTextLabel;
    QLabel *stateLabel;
    QLabel *queueTextLabel;
    QLabel *queueLabel;
    QLabel *cycleTextLabel;
    QLabel *cycleLabel;
    QLabel *errorTextLabel;
    QLabel *errorLabel;
    QGroupBox *tipBox;
    QVBoxLayout *tipLayout;
    QLabel *tipLabel;
    QWidget *errorPlotHost;
    QPlainTextEdit *logEdit;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1180, 920);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        rootLayout = new QVBoxLayout(centralwidget);
        rootLayout->setObjectName("rootLayout");
        topLayout = new QHBoxLayout();
        topLayout->setObjectName("topLayout");
        leftLayout = new QVBoxLayout();
        leftLayout->setObjectName("leftLayout");
        motionGroupBox = new QGroupBox(centralwidget);
        motionGroupBox->setObjectName("motionGroupBox");
        motionFormLayout = new QFormLayout(motionGroupBox);
        motionFormLayout->setObjectName("motionFormLayout");
        axisLabel = new QLabel(motionGroupBox);
        axisLabel->setObjectName("axisLabel");

        motionFormLayout->setWidget(0, QFormLayout::LabelRole, axisLabel);

        axisSpin = new QSpinBox(motionGroupBox);
        axisSpin->setObjectName("axisSpin");
        axisSpin->setMaximum(63);

        motionFormLayout->setWidget(0, QFormLayout::FieldRole, axisSpin);

        modeLabel = new QLabel(motionGroupBox);
        modeLabel->setObjectName("modeLabel");

        motionFormLayout->setWidget(1, QFormLayout::LabelRole, modeLabel);

        modeCombo = new QComboBox(motionGroupBox);
        modeCombo->setObjectName("modeCombo");

        motionFormLayout->setWidget(1, QFormLayout::FieldRole, modeCombo);

        deltaAngleLabel = new QLabel(motionGroupBox);
        deltaAngleLabel->setObjectName("deltaAngleLabel");

        motionFormLayout->setWidget(2, QFormLayout::LabelRole, deltaAngleLabel);

        deltaAngleSpin = new QDoubleSpinBox(motionGroupBox);
        deltaAngleSpin->setObjectName("deltaAngleSpin");
        deltaAngleSpin->setMinimum(-999999.000000000000000);
        deltaAngleSpin->setMaximum(999999.000000000000000);
        deltaAngleSpin->setDecimals(3);
        deltaAngleSpin->setValue(300.000000000000000);

        motionFormLayout->setWidget(2, QFormLayout::FieldRole, deltaAngleSpin);

        durationLabel = new QLabel(motionGroupBox);
        durationLabel->setObjectName("durationLabel");

        motionFormLayout->setWidget(3, QFormLayout::LabelRole, durationLabel);

        durationSpin = new QDoubleSpinBox(motionGroupBox);
        durationSpin->setObjectName("durationSpin");
        durationSpin->setMinimum(0.050000000000000);
        durationSpin->setMaximum(3600.000000000000000);
        durationSpin->setDecimals(3);
        durationSpin->setValue(15.000000000000000);

        motionFormLayout->setWidget(3, QFormLayout::FieldRole, durationSpin);

        systemPlanningPeriodLabel = new QLabel(motionGroupBox);
        systemPlanningPeriodLabel->setObjectName("systemPlanningPeriodLabel");

        motionFormLayout->setWidget(4, QFormLayout::LabelRole, systemPlanningPeriodLabel);

        systemPlanningPeriodMsSpin = new QSpinBox(motionGroupBox);
        systemPlanningPeriodMsSpin->setObjectName("systemPlanningPeriodMsSpin");
        systemPlanningPeriodMsSpin->setMinimum(1);
        systemPlanningPeriodMsSpin->setMaximum(1000);
        systemPlanningPeriodMsSpin->setValue(10);

        motionFormLayout->setWidget(4, QFormLayout::FieldRole, systemPlanningPeriodMsSpin);

        minVelLabel = new QLabel(motionGroupBox);
        minVelLabel->setObjectName("minVelLabel");

        motionFormLayout->setWidget(5, QFormLayout::LabelRole, minVelLabel);

        minVelSpin = new QDoubleSpinBox(motionGroupBox);
        minVelSpin->setObjectName("minVelSpin");
        minVelSpin->setMaximum(100000.000000000000000);
        minVelSpin->setDecimals(3);

        motionFormLayout->setWidget(5, QFormLayout::FieldRole, minVelSpin);

        maxVelLabel = new QLabel(motionGroupBox);
        maxVelLabel->setObjectName("maxVelLabel");

        motionFormLayout->setWidget(6, QFormLayout::LabelRole, maxVelLabel);

        maxVelSpin = new QDoubleSpinBox(motionGroupBox);
        maxVelSpin->setObjectName("maxVelSpin");
        maxVelSpin->setMinimum(0.001000000000000);
        maxVelSpin->setMaximum(100000.000000000000000);
        maxVelSpin->setDecimals(3);
        maxVelSpin->setValue(60.000000000000000);

        motionFormLayout->setWidget(6, QFormLayout::FieldRole, maxVelSpin);


        leftLayout->addWidget(motionGroupBox);

        displayGroupBox = new QGroupBox(centralwidget);
        displayGroupBox->setObjectName("displayGroupBox");
        displayFormLayout = new QFormLayout(displayGroupBox);
        displayFormLayout->setObjectName("displayFormLayout");
        uiRefreshLabel = new QLabel(displayGroupBox);
        uiRefreshLabel->setObjectName("uiRefreshLabel");

        displayFormLayout->setWidget(0, QFormLayout::LabelRole, uiRefreshLabel);

        uiRefreshMsSpin = new QSpinBox(displayGroupBox);
        uiRefreshMsSpin->setObjectName("uiRefreshMsSpin");
        uiRefreshMsSpin->setMinimum(10);
        uiRefreshMsSpin->setMaximum(500);
        uiRefreshMsSpin->setValue(50);

        displayFormLayout->setWidget(0, QFormLayout::FieldRole, uiRefreshMsSpin);


        leftLayout->addWidget(displayGroupBox);

        cspRuntimeGroupBox = new QGroupBox(centralwidget);
        cspRuntimeGroupBox->setObjectName("cspRuntimeGroupBox");
        cspRuntimeFormLayout = new QFormLayout(cspRuntimeGroupBox);
        cspRuntimeFormLayout->setObjectName("cspRuntimeFormLayout");
        ecatPortLabel = new QLabel(cspRuntimeGroupBox);
        ecatPortLabel->setObjectName("ecatPortLabel");

        cspRuntimeFormLayout->setWidget(0, QFormLayout::LabelRole, ecatPortLabel);

        ecatPortSpin = new QSpinBox(cspRuntimeGroupBox);
        ecatPortSpin->setObjectName("ecatPortSpin");
        ecatPortSpin->setMaximum(8);
        ecatPortSpin->setValue(2);

        cspRuntimeFormLayout->setWidget(0, QFormLayout::FieldRole, ecatPortSpin);

        nodeLabel = new QLabel(cspRuntimeGroupBox);
        nodeLabel->setObjectName("nodeLabel");

        cspRuntimeFormLayout->setWidget(1, QFormLayout::LabelRole, nodeLabel);

        nodeSpin = new QSpinBox(cspRuntimeGroupBox);
        nodeSpin->setObjectName("nodeSpin");
        nodeSpin->setMinimum(1);
        nodeSpin->setMaximum(65535);
        nodeSpin->setValue(1);

        cspRuntimeFormLayout->setWidget(1, QFormLayout::FieldRole, nodeSpin);

        cspInterpPeriodMsLabel = new QLabel(cspRuntimeGroupBox);
        cspInterpPeriodMsLabel->setObjectName("cspInterpPeriodMsLabel");

        cspRuntimeFormLayout->setWidget(2, QFormLayout::LabelRole, cspInterpPeriodMsLabel);

        cspInterpPeriodMsSpin = new QSpinBox(cspRuntimeGroupBox);
        cspInterpPeriodMsSpin->setObjectName("cspInterpPeriodMsSpin");
        cspInterpPeriodMsSpin->setMinimum(1);
        cspInterpPeriodMsSpin->setMaximum(4);
        cspInterpPeriodMsSpin->setValue(1);

        cspRuntimeFormLayout->setWidget(2, QFormLayout::FieldRole, cspInterpPeriodMsSpin);

        cspInterpIndexLabel = new QLabel(cspRuntimeGroupBox);
        cspInterpIndexLabel->setObjectName("cspInterpIndexLabel");

        cspRuntimeFormLayout->setWidget(3, QFormLayout::LabelRole, cspInterpIndexLabel);

        cspInterpIndexSpin = new QSpinBox(cspRuntimeGroupBox);
        cspInterpIndexSpin->setObjectName("cspInterpIndexSpin");
        cspInterpIndexSpin->setMinimum(-10);
        cspInterpIndexSpin->setMaximum(0);
        cspInterpIndexSpin->setValue(-3);

        cspRuntimeFormLayout->setWidget(3, QFormLayout::FieldRole, cspInterpIndexSpin);


        leftLayout->addWidget(cspRuntimeGroupBox);

        advancedGroupBox = new QGroupBox(centralwidget);
        advancedGroupBox->setObjectName("advancedGroupBox");
        advancedFormLayout = new QFormLayout(advancedGroupBox);
        advancedFormLayout->setObjectName("advancedFormLayout");
        positionUnitLabel = new QLabel(advancedGroupBox);
        positionUnitLabel->setObjectName("positionUnitLabel");

        advancedFormLayout->setWidget(0, QFormLayout::LabelRole, positionUnitLabel);

        positionUnitLayout = new QHBoxLayout();
        positionUnitLayout->setObjectName("positionUnitLayout");
        degreeUnitRadio = new QRadioButton(advancedGroupBox);
        degreeUnitRadio->setObjectName("degreeUnitRadio");
        degreeUnitRadio->setChecked(true);

        positionUnitLayout->addWidget(degreeUnitRadio);

        turnUnitRadio = new QRadioButton(advancedGroupBox);
        turnUnitRadio->setObjectName("turnUnitRadio");

        positionUnitLayout->addWidget(turnUnitRadio);


        advancedFormLayout->setLayout(0, QFormLayout::FieldRole, positionUnitLayout);

        cspRxpdoPosAddrLabel = new QLabel(advancedGroupBox);
        cspRxpdoPosAddrLabel->setObjectName("cspRxpdoPosAddrLabel");

        advancedFormLayout->setWidget(1, QFormLayout::LabelRole, cspRxpdoPosAddrLabel);

        cspRxpdoPosAddrSpin = new QSpinBox(advancedGroupBox);
        cspRxpdoPosAddrSpin->setObjectName("cspRxpdoPosAddrSpin");
        cspRxpdoPosAddrSpin->setMaximum(65535);
        cspRxpdoPosAddrSpin->setValue(1);

        advancedFormLayout->setWidget(1, QFormLayout::FieldRole, cspRxpdoPosAddrSpin);

        cspTxpdoStatusAddrLabel = new QLabel(advancedGroupBox);
        cspTxpdoStatusAddrLabel->setObjectName("cspTxpdoStatusAddrLabel");

        advancedFormLayout->setWidget(2, QFormLayout::LabelRole, cspTxpdoStatusAddrLabel);

        cspTxpdoStatusAddrSpin = new QSpinBox(advancedGroupBox);
        cspTxpdoStatusAddrSpin->setObjectName("cspTxpdoStatusAddrSpin");
        cspTxpdoStatusAddrSpin->setMaximum(65535);

        advancedFormLayout->setWidget(2, QFormLayout::FieldRole, cspTxpdoStatusAddrSpin);

        cspTxpdoModeAddrLabel = new QLabel(advancedGroupBox);
        cspTxpdoModeAddrLabel->setObjectName("cspTxpdoModeAddrLabel");

        advancedFormLayout->setWidget(3, QFormLayout::LabelRole, cspTxpdoModeAddrLabel);

        cspTxpdoModeAddrSpin = new QSpinBox(advancedGroupBox);
        cspTxpdoModeAddrSpin->setObjectName("cspTxpdoModeAddrSpin");
        cspTxpdoModeAddrSpin->setMaximum(65535);
        cspTxpdoModeAddrSpin->setValue(3);

        advancedFormLayout->setWidget(3, QFormLayout::FieldRole, cspTxpdoModeAddrSpin);

        cspTxpdoPosAddrLabel = new QLabel(advancedGroupBox);
        cspTxpdoPosAddrLabel->setObjectName("cspTxpdoPosAddrLabel");

        advancedFormLayout->setWidget(4, QFormLayout::LabelRole, cspTxpdoPosAddrLabel);

        cspTxpdoPosAddrSpin = new QSpinBox(advancedGroupBox);
        cspTxpdoPosAddrSpin->setObjectName("cspTxpdoPosAddrSpin");
        cspTxpdoPosAddrSpin->setMaximum(65535);
        cspTxpdoPosAddrSpin->setValue(1);

        advancedFormLayout->setWidget(4, QFormLayout::FieldRole, cspTxpdoPosAddrSpin);


        leftLayout->addWidget(advancedGroupBox);


        topLayout->addLayout(leftLayout);

        rightLayout = new QVBoxLayout();
        rightLayout->setObjectName("rightLayout");
        buttonBox = new QGroupBox(centralwidget);
        buttonBox->setObjectName("buttonBox");
        buttonLayout = new QGridLayout(buttonBox);
        buttonLayout->setObjectName("buttonLayout");
        initCardButton = new QPushButton(buttonBox);
        initCardButton->setObjectName("initCardButton");

        buttonLayout->addWidget(initCardButton, 0, 0, 1, 1);

        closeCardButton = new QPushButton(buttonBox);
        closeCardButton->setObjectName("closeCardButton");

        buttonLayout->addWidget(closeCardButton, 0, 1, 1, 1);

        enableAxisButton = new QPushButton(buttonBox);
        enableAxisButton->setObjectName("enableAxisButton");

        buttonLayout->addWidget(enableAxisButton, 1, 0, 1, 1);

        disableAxisButton = new QPushButton(buttonBox);
        disableAxisButton->setObjectName("disableAxisButton");

        buttonLayout->addWidget(disableAxisButton, 1, 1, 1, 1);

        readPosButton = new QPushButton(buttonBox);
        readPosButton->setObjectName("readPosButton");

        buttonLayout->addWidget(readPosButton, 2, 0, 1, 1);

        stopButton = new QPushButton(buttonBox);
        stopButton->setObjectName("stopButton");

        buttonLayout->addWidget(stopButton, 2, 1, 1, 1);

        startButton = new QPushButton(buttonBox);
        startButton->setObjectName("startButton");

        buttonLayout->addWidget(startButton, 3, 0, 1, 2);


        rightLayout->addWidget(buttonBox);

        statusBox = new QGroupBox(centralwidget);
        statusBox->setObjectName("statusBox");
        statusLayout = new QFormLayout(statusBox);
        statusLayout->setObjectName("statusLayout");
        connectionTextLabel = new QLabel(statusBox);
        connectionTextLabel->setObjectName("connectionTextLabel");

        statusLayout->setWidget(0, QFormLayout::LabelRole, connectionTextLabel);

        connectionLabel = new QLabel(statusBox);
        connectionLabel->setObjectName("connectionLabel");

        statusLayout->setWidget(0, QFormLayout::FieldRole, connectionLabel);

        positionTextLabel = new QLabel(statusBox);
        positionTextLabel->setObjectName("positionTextLabel");

        statusLayout->setWidget(1, QFormLayout::LabelRole, positionTextLabel);

        positionLabel = new QLabel(statusBox);
        positionLabel->setObjectName("positionLabel");

        statusLayout->setWidget(1, QFormLayout::FieldRole, positionLabel);

        stateTextLabel = new QLabel(statusBox);
        stateTextLabel->setObjectName("stateTextLabel");

        statusLayout->setWidget(2, QFormLayout::LabelRole, stateTextLabel);

        stateLabel = new QLabel(statusBox);
        stateLabel->setObjectName("stateLabel");

        statusLayout->setWidget(2, QFormLayout::FieldRole, stateLabel);

        queueTextLabel = new QLabel(statusBox);
        queueTextLabel->setObjectName("queueTextLabel");

        statusLayout->setWidget(3, QFormLayout::LabelRole, queueTextLabel);

        queueLabel = new QLabel(statusBox);
        queueLabel->setObjectName("queueLabel");

        statusLayout->setWidget(3, QFormLayout::FieldRole, queueLabel);

        cycleTextLabel = new QLabel(statusBox);
        cycleTextLabel->setObjectName("cycleTextLabel");

        statusLayout->setWidget(4, QFormLayout::LabelRole, cycleTextLabel);

        cycleLabel = new QLabel(statusBox);
        cycleLabel->setObjectName("cycleLabel");

        statusLayout->setWidget(4, QFormLayout::FieldRole, cycleLabel);

        errorTextLabel = new QLabel(statusBox);
        errorTextLabel->setObjectName("errorTextLabel");

        statusLayout->setWidget(5, QFormLayout::LabelRole, errorTextLabel);

        errorLabel = new QLabel(statusBox);
        errorLabel->setObjectName("errorLabel");

        statusLayout->setWidget(5, QFormLayout::FieldRole, errorLabel);


        rightLayout->addWidget(statusBox);

        tipBox = new QGroupBox(centralwidget);
        tipBox->setObjectName("tipBox");
        tipLayout = new QVBoxLayout(tipBox);
        tipLayout->setObjectName("tipLayout");
        tipLabel = new QLabel(tipBox);
        tipLabel->setObjectName("tipLabel");
        tipLabel->setWordWrap(true);

        tipLayout->addWidget(tipLabel);


        rightLayout->addWidget(tipBox);


        topLayout->addLayout(rightLayout);


        rootLayout->addLayout(topLayout);

        errorPlotHost = new QWidget(centralwidget);
        errorPlotHost->setObjectName("errorPlotHost");

        rootLayout->addWidget(errorPlotHost);

        logEdit = new QPlainTextEdit(centralwidget);
        logEdit->setObjectName("logEdit");
        logEdit->setReadOnly(true);

        rootLayout->addWidget(logEdit);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1180, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "Qt \345\244\232\347\272\277\347\250\213\350\277\220\345\212\250\346\216\247\345\210\266\346\241\206\346\236\266", nullptr));
        motionGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\345\237\272\347\241\200\350\277\220\345\212\250\345\217\202\346\225\260", nullptr));
        axisLabel->setText(QCoreApplication::translate("MainWindow", "\350\275\264\345\217\267", nullptr));
        modeLabel->setText(QCoreApplication::translate("MainWindow", "\346\250\241\345\274\217", nullptr));
        deltaAngleLabel->setText(QCoreApplication::translate("MainWindow", "\347\233\270\345\257\271\350\247\222\345\272\246\345\242\236\351\207\217", nullptr));
        deltaAngleSpin->setSuffix(QCoreApplication::translate("MainWindow", " deg", nullptr));
        durationLabel->setText(QCoreApplication::translate("MainWindow", "\346\225\264\346\256\265\346\227\266\351\227\264", nullptr));
        durationSpin->setSuffix(QCoreApplication::translate("MainWindow", " s", nullptr));
        systemPlanningPeriodLabel->setText(QCoreApplication::translate("MainWindow", "\347\263\273\347\273\237\350\247\204\345\210\222\345\221\250\346\234\237", nullptr));
        systemPlanningPeriodMsSpin->setSuffix(QCoreApplication::translate("MainWindow", " ms", nullptr));
        minVelLabel->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\260\217\351\200\237\345\272\246", nullptr));
        minVelSpin->setSuffix(QCoreApplication::translate("MainWindow", " deg/s", nullptr));
        maxVelLabel->setText(QCoreApplication::translate("MainWindow", "\346\234\200\345\244\247\351\200\237\345\272\246", nullptr));
        maxVelSpin->setSuffix(QCoreApplication::translate("MainWindow", " deg/s", nullptr));
        displayGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\346\230\276\347\244\272\344\270\216\345\210\267\346\226\260", nullptr));
        uiRefreshLabel->setText(QCoreApplication::translate("MainWindow", "UI\346\230\276\347\244\272\345\221\250\346\234\237", nullptr));
        uiRefreshMsSpin->setSuffix(QCoreApplication::translate("MainWindow", " ms", nullptr));
        cspRuntimeGroupBox->setTitle(QCoreApplication::translate("MainWindow", "CSP\350\277\220\350\241\214\345\217\202\346\225\260", nullptr));
        ecatPortLabel->setText(QCoreApplication::translate("MainWindow", "EtherCAT\347\253\257\345\217\243", nullptr));
        nodeLabel->setText(QCoreApplication::translate("MainWindow", "\344\273\216\347\253\231\345\272\217\345\217\267", nullptr));
        cspInterpPeriodMsLabel->setText(QCoreApplication::translate("MainWindow", "\351\251\261\345\212\250\346\217\222\350\241\245\345\221\250\346\234\237(0x60C2:01)", nullptr));
        cspInterpPeriodMsSpin->setSuffix(QCoreApplication::translate("MainWindow", " ms", nullptr));
        cspInterpIndexLabel->setText(QCoreApplication::translate("MainWindow", "\346\227\266\351\227\264\345\237\272\346\214\207\346\225\260(0x60C2:02)", nullptr));
        advancedGroupBox->setTitle(QCoreApplication::translate("MainWindow", "\351\253\230\347\272\247\350\256\276\347\275\256", nullptr));
        positionUnitLabel->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\347\274\251\346\224\276", nullptr));
        degreeUnitRadio->setText(QCoreApplication::translate("MainWindow", "\347\221\231\346\216\221\345\256\263", nullptr));
        turnUnitRadio->setText(QCoreApplication::translate("MainWindow", "\351\215\246\345\240\237\346\232\237", nullptr));
        cspRxpdoPosAddrLabel->setText(QCoreApplication::translate("MainWindow", "\347\233\256\346\240\207\344\275\215\347\275\256\345\234\260\345\235\200(RxPDO)", nullptr));
        cspTxpdoStatusAddrLabel->setText(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201\345\255\227\345\234\260\345\235\200(TxPDO 0x6041)", nullptr));
        cspTxpdoModeAddrLabel->setText(QCoreApplication::translate("MainWindow", "\346\250\241\345\274\217\346\230\276\347\244\272\345\234\260\345\235\200(TxPDO 0x6061)", nullptr));
        cspTxpdoPosAddrLabel->setText(QCoreApplication::translate("MainWindow", "\345\256\236\351\231\205\344\275\215\347\275\256\345\234\260\345\235\200(TxPDO 0x6064)", nullptr));
        buttonBox->setTitle(QCoreApplication::translate("MainWindow", "\346\216\247\345\210\266", nullptr));
        initCardButton->setText(QCoreApplication::translate("MainWindow", "\345\210\235\345\247\213\345\214\226\346\216\247\345\210\266\345\215\241", nullptr));
        closeCardButton->setText(QCoreApplication::translate("MainWindow", "\345\205\263\351\227\255\346\216\247\345\210\266\345\215\241", nullptr));
        enableAxisButton->setText(QCoreApplication::translate("MainWindow", "\350\275\264\344\275\277\350\203\275", nullptr));
        disableAxisButton->setText(QCoreApplication::translate("MainWindow", "\350\275\264\345\244\261\350\203\275", nullptr));
        readPosButton->setText(QCoreApplication::translate("MainWindow", "\350\257\273\345\217\226\347\262\227\347\262\222\345\272\246\344\275\215\347\275\256", nullptr));
        stopButton->setText(QCoreApplication::translate("MainWindow", "\345\201\234\346\255\242\350\275\250\350\277\271", nullptr));
        startButton->setText(QCoreApplication::translate("MainWindow", "\345\274\200\345\247\213\350\275\250\350\277\271", nullptr));
        statusBox->setTitle(QCoreApplication::translate("MainWindow", "\347\212\266\346\200\201", nullptr));
        connectionTextLabel->setText(QCoreApplication::translate("MainWindow", "\346\216\247\345\210\266\345\215\241", nullptr));
        connectionLabel->setText(QCoreApplication::translate("MainWindow", "\346\234\252\345\210\235\345\247\213\345\214\226", nullptr));
        positionTextLabel->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\344\275\215\347\275\256", nullptr));
        positionLabel->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        stateTextLabel->setText(QCoreApplication::translate("MainWindow", "\350\277\220\350\241\214\347\212\266\346\200\201", nullptr));
        stateLabel->setText(QCoreApplication::translate("MainWindow", "\347\251\272\351\227\262", nullptr));
        queueTextLabel->setText(QCoreApplication::translate("MainWindow", "\350\275\250\350\277\271\351\230\237\345\210\227\346\267\261\345\272\246", nullptr));
        queueLabel->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        cycleTextLabel->setText(QCoreApplication::translate("MainWindow", "\345\267\262\345\217\221\351\200\201/\350\241\245\351\230\237\345\210\227", nullptr));
        cycleLabel->setText(QCoreApplication::translate("MainWindow", "--", nullptr));
        errorTextLabel->setText(QCoreApplication::translate("MainWindow", "\344\275\215\347\275\256\350\257\257\345\267\256", nullptr));
        errorLabel->setText(QCoreApplication::translate("MainWindow", "\345\275\223\345\211\215\344\275\215\347\275\256\350\257\257\345\267\256: -- deg", nullptr));
        tipBox->setTitle(QCoreApplication::translate("MainWindow", "\346\236\266\346\236\204\350\257\264\346\230\216", nullptr));
        tipLabel->setText(QCoreApplication::translate("MainWindow", "1. \347\263\273\347\273\237\350\247\204\345\210\222\345\221\250\346\234\237\347\224\250\344\272\216\344\270\212\345\261\202\347\262\227\350\247\204\345\210\222\343\200\202CSP \344\274\232\345\234\250\346\255\244\345\237\272\347\241\200\344\270\212\347\273\206\345\214\226\345\210\260 1ms\357\274\233PVT(PVTS) \344\274\232\347\233\264\346\216\245\346\214\211\350\257\245\345\221\250\346\234\237\347\224\237\346\210\220\346\225\264\350\241\250\347\202\271\345\210\227\343\200\202\n"
"2. PVT \347\202\271\346\225\260\344\274\260\347\256\227\347\272\246\344\270\272 ceil(\346\200\273\346\227\266\351\225\277 / \347\263\273\347\273\237\350\247\204\345\210\222\345\221\250\346\234\237) + 1\357\274\214\345\275\223\345\211\215\346\216\247\345\210\266\345\215\241\344\270\212\351\231\220\344\270\272 5000 \347\202\271\343\200\202\n"
"3. \345\246\202\346\236\234 PVT \347\202\271\346\225\260\346\216\245\350\277\221\344\270\212\351\231\220\357\274\214\350\257\267\345\242\236\345\244\247\347\263\273\347\273\237\350\247\204\345\210\222"
                        "\345\221\250\346\234\237\346\210\226\347\274\251\347\237\255\346\200\273\346\227\266\351\225\277\357\274\214\351\201\277\345\205\215\346\225\264\350\241\250\344\270\213\345\217\221\345\244\261\350\264\245\343\200\202\n"
"4. CSP \347\224\261\347\241\254\344\273\266\347\272\277\347\250\213\346\257\217 1ms \346\266\210\350\264\271\345\205\261\344\272\253\351\230\237\345\210\227\344\270\255\347\232\204\344\270\200\344\270\252\347\202\271\357\274\233PVT \347\224\261\347\241\254\344\273\266\347\272\277\347\250\213\344\270\200\346\254\241\346\200\247\350\243\205\350\241\250\345\220\257\345\212\250\357\274\214\350\277\220\350\241\214\346\234\237\345\217\252\345\201\232\347\233\221\346\265\213\343\200\202\n"
"5. UI \346\230\276\347\244\272\345\221\250\346\234\237\345\217\252\350\264\237\350\264\243\347\225\214\351\235\242\345\210\267\346\226\260\357\274\214\344\270\215\345\217\202\344\270\216\345\256\236\346\227\266\346\216\247\345\210\266\343\200\202", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
