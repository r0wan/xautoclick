/* xAutoClick, Qt GUI
 *
 * Copyright (C) 2010 Ivo van Poorten
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA  02110-1301  USA
 *
 */

#include "clickwidget.h"

extern "C" {
#include "gui.h"
#include "main.h"
}

#include <QHBoxLayout>
#include <QLabel>
#include <QPushButton>
#include <QSpinBox>
#include <QVBoxLayout>

#include <climits>

ClickWidget::ClickWidget(const spin_param_t* spin_params, QWidget *parent) : QWidget(parent) {
    std::array<QString, BUTTONS_COUNT> btnNames = { "Tap", "Stop", "Start" };

    auto vbox = new QVBoxLayout;

    for (int c = 0; c < SPINS_COUNT; c++) {
        spins[c] = new QSpinBox;
        spins[c]->setRange(spin_params[c].min_value, INT_MAX);
        if (spin_params[c].suffix && *spin_params[c].suffix != '\0')
            spins[c]->setSuffix(QString(" ") + spin_params[c].suffix);

        auto layout = new QHBoxLayout;
        layout->addWidget(new QLabel(spin_params[c].descr));
        layout->addWidget(spins[c]);
        vbox->addLayout(layout);
    }

    auto layout = new QHBoxLayout;

    for (int c = 0; c < BUTTONS_COUNT; c++)
        layout->addWidget(buttons[c] = new QPushButton(btnNames[c]));

    connect(buttons[BUTTON_TAP], &QPushButton::clicked, common_tap_button);
    connect(buttons[BUTTON_STOP], &QPushButton::clicked, common_stop_button);
    connect(buttons[BUTTON_START], &QPushButton::clicked, common_start_button);

    vbox->addLayout(layout);
    setWindowIcon(QIcon::fromTheme("xautoclick"));
    setWindowTitle("qAutoClick");
    setLayout(vbox);
}

int ClickWidget::getSpinValue(int spin) {
    return spins[spin]->value();
}

void ClickWidget::setSpinValue(int spin, int value) {
    spins[spin]->setValue(value);
}

void ClickWidget::setButtonSensitive(int button, bool state) {
    buttons[button]->setEnabled(state);
}
