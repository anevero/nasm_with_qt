#include "mainwindow.h"

#include <QMessageBox>

MainWindow::MainWindow(QWidget* parent)
    : QMainWindow(parent),
      buttons_layout_(),
      text_layout_(),
      enter_data_button_("Enter data", this),
      get_result_button_("Get Result", this),
      current_data_label_("Current data:", this),
      first_number_label_(this),
      second_number_label_(this),
      enter_data_dialog_() {
  setMinimumSize(350, 150);
  setMaximumSize(490, 210);
  resize(350, 150);
  setWindowTitle("Task");

  enter_data_button_.setSizePolicy(
      {QSizePolicy::Expanding, QSizePolicy::Expanding});
  get_result_button_.setSizePolicy(
      {QSizePolicy::Expanding, QSizePolicy::Expanding});

  current_data_label_.setWordWrap(true);
  first_number_label_.setWordWrap(true);
  second_number_label_.setWordWrap(true);

  buttons_layout_.addWidget(&enter_data_button_);
  buttons_layout_.addWidget(&get_result_button_);
  buttons_layout_.setStretch(0, 1);
  buttons_layout_.setStretch(1, 1);

  text_layout_.addWidget(&current_data_label_);
  text_layout_.addWidget(&first_number_label_);
  text_layout_.addWidget(&second_number_label_);

  connect(&get_result_button_, &QPushButton::clicked, [this]() {
    double res = 0;
    assembly_function(&first_number_, &second_number_, &res);
    QMessageBox result_dialog(QMessageBox::Information, "Result",
                              "Result: " + QString::number(res));
    result_dialog.exec();
  });

  connect(&enter_data_button_, &QPushButton::clicked, [this]() {
    if (enter_data_dialog_.exec() == QDialog::Accepted) {
      first_number_ = enter_data_dialog_.GetFirstNumber();
      second_number_ = enter_data_dialog_.GetSecondNumber();
      enter_data_dialog_.ClearTextFields();
      UpdateCurrentDataLabels();
    }
  });

  ResizeLayouts();
  UpdateCurrentDataLabels();
}

void MainWindow::ResizeLayouts() {
  layout_spacing_ = static_cast<int32_t>(0.01 * width());
  window_spacing_ = static_cast<int32_t>(0.05 * width());

  buttons_layout_.setGeometry({window_spacing_, window_spacing_,
                               (width() - 3 * window_spacing_) / 2,
                               height() - 2 * window_spacing_});
  text_layout_.setGeometry(
      {2 * window_spacing_ + (width() - 3 * window_spacing_) / 2,
       window_spacing_, (width() - 3 * window_spacing_) / 2,
       height() - 2 * window_spacing_});

  buttons_layout_.setSpacing(layout_spacing_);
  text_layout_.setSpacing(layout_spacing_);
}

void MainWindow::resizeEvent(QResizeEvent* event) {
  ResizeLayouts();
  return QMainWindow::resizeEvent(event);
}

void MainWindow::UpdateCurrentDataLabels() {
  first_number_label_.setText(
      "First number: " + QString::number(first_number_));
  second_number_label_.setText(
      "Second number: " + QString::number(second_number_));
}
