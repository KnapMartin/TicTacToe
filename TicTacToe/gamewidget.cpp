#include "gamewidget.h"

GameWidget::GameWidget(int gameSize, QWidget *parent)
    : QWidget{parent},
      m_gameSize{gameSize},
      m_buttons{},
      m_buttonLayout{this}
{
    // set initial geometry
    QRect geom;
    geom.setHeight(::mainWindowHeight);
    geom.setWidth(::mainWindowWidth);
    this->setGeometry(geom);

    // set color
    QPalette widgetPalette;
    QColor widgetColor;
    widgetColor.setNamedColor(::gamewidgetColor);
    widgetPalette.setColor(QPalette::Window, widgetColor);
    this->setPalette(widgetPalette);

    // set up buttons
    this->createButtons();
    this->positionButtons();
}

void GameWidget::toggleButton(int row, int col)
{
    QList< GameButton* > rowButtons = m_buttons.value(row);
    GameButton *button = rowButtons.value(col);

    button->toggle();
    button->setEnabled(false);
}

void GameWidget::handleGameButtonClicked(int row, int col)
{
    QList< GameButton* > rowButtons = m_buttons.value(row);
    GameButton *button = rowButtons.value(col);
    button->setEnabled(false);
}

void GameWidget::createButtons()
{
    for (int row = 0; row < m_gameSize; ++row)
    {
        QList< GameButton* > rowButtons;
        for (int col = 0; col < m_gameSize; ++col)
        {
            GameButton* button = new GameButton();
            button->setCheckable(true);
            button->setPosition(row, col);
            QObject::connect(button, &GameButton::buttonToggled, this, &GameWidget::handleGameButtonClicked);
            rowButtons.append(button);
        }
        m_buttons.append(rowButtons);
    }
}

void GameWidget::deleteButtons()
{
    for (int row = 0; row < m_gameSize; ++row)
    {
        QList< GameButton* > rowButtons = m_buttons.value(row);
        for (int col = 0; col < m_gameSize; ++col)
        {
            GameButton* button = rowButtons.value(row);
            delete button;
        }
    }
}

void GameWidget::positionButtons()
{
    for (int row = 0; row < m_gameSize; ++row)
    {
        QList< GameButton* > rowButtons = m_buttons.value(row);
        for (int col = 0; col < m_gameSize; ++col)
        {
            GameButton* button = rowButtons.value(col);
            button->setSizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum); // fit to gird
            m_buttonLayout.addWidget(button, row, col);
        }
    }
    m_buttonLayout.setHorizontalSpacing(::gameWidgetHorizontalSpacing);
    m_buttonLayout.setVerticalSpacing(::gameWidgetVerticalSpacing);
}

