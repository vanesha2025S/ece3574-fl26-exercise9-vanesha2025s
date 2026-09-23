////////////////////////////////////////////////////////
// ECE 3574 - Exercise 9: Qt widgets
//

#include "complex_widget.hpp"

#include <QGridLayout>
#include <cmath>

ComplexWidget::ComplexWidget(QWidget *parent)
    : QWidget(parent)
{
    //create the input boxes
    realEdit = new QLineEdit;
    imaginaryEdit = new QLineEdit;

    //create the output labels
    magnitudeLabel = new QLabel("0");
    phaseLabel = new QLabel("0");

    //create the update button
    updateButton = new QPushButton("Update");

    //create labels for each value
    QLabel *realLabel = new QLabel("Real Part:");
    QLabel *imaginaryLabel = new QLabel("Imaginary Part:");
    QLabel *magLabel = new QLabel("Magnitude:");
    QLabel *phaseTextLabel = new QLabel("Phase:");

    //set up the layout
    QGridLayout *layout = new QGridLayout;

    layout->addWidget(realLabel, 0, 0);
    layout->addWidget(realEdit, 0, 1);

    layout->addWidget(imaginaryLabel, 1, 0);
    layout->addWidget(imaginaryEdit, 1, 1);

    layout->addWidget(magLabel, 2, 0);
    layout->addWidget(magnitudeLabel, 2, 1);

    layout->addWidget(phaseTextLabel, 3, 0);
    layout->addWidget(phaseLabel, 3, 1);

    layout->addWidget(updateButton, 4, 0, 1, 2);

    setLayout(layout);

    //update the values when the button is clicked
    connect(updateButton, &QPushButton::clicked, this, &ComplexWidget::updateDisplay);
}

double ComplexWidget::getRealPart() const
{
    return realEdit->text().toDouble();
}

double ComplexWidget::getImaginaryPart() const
{
    return imaginaryEdit->text().toDouble();
}

double ComplexWidget::getMagnitude() const
{
    double real = getRealPart();
    double imaginary = getImaginaryPart();

    return std::sqrt(real * real + imaginary * imaginary);
}

double ComplexWidget::getPhase() const
{
    double real = getRealPart();
    double imaginary = getImaginaryPart();

    return std::atan2(imaginary, real);
}

void ComplexWidget::updateDisplay()
{
    magnitudeLabel->setText(QString::number(getMagnitude()));
    phaseLabel->setText(QString::number(getPhase()));
}
