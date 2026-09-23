////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//
#ifndef COMPLEX_WIDGET_H
#define COMPLEX_WIDGET_H
#include <QWidget>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>

class ComplexWidget : public QWidget
{
    Q_OBJECT

public:
    ComplexWidget(QWidget *parent = nullptr);

    double getRealPart() const;
    double getImaginaryPart() const;
    double getMagnitude() const;
    double getPhase() const;

private slots:
    void updateDisplay();

private:
    QLineEdit *realEdit;
    QLineEdit *imaginaryEdit;

    QLabel *magnitudeLabel;
    QLabel *phaseLabel;

    QPushButton *updateButton;
};

#endif
