#include "gamebutton.h"

GameButton::GameButton(QPushButton *parent)
    : QPushButton{parent},
      m_row{-1},
      m_col{-1}
{
    QObject::connect(this, &GameButton::clicked, this, &GameButton::handleClicked);
}

void GameButton::setPosition(const int row, const int col)
{
    m_row = row;
    m_col = col;
}

void GameButton::handleClicked()
{
    emit buttonToggled(m_row, m_col);
}
