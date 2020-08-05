#ifndef MAINWINDOW_H_
#define MAINWINDOW_H_

#include <cstdint>

#include <QLabel>
#include <QMainWindow>
#include <QPushButton>
#include <QVBoxLayout>

#include "customdialog.h"

extern "C" {
void assembly_function(double*, double*, double*);
}

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  explicit MainWindow(QWidget* parent = nullptr);
  ~MainWindow() override = default;

 private:
  void resizeEvent(QResizeEvent* event) override;
  void ResizeLayouts();
  void UpdateCurrentDataLabels();

 private:
  int32_t window_spacing_ = 0;
  int32_t layout_spacing_ = 0;

  QVBoxLayout buttons_layout_;
  QVBoxLayout text_layout_;

  QPushButton enter_data_button_;
  QPushButton get_result_button_;
  QLabel current_data_label_;
  QLabel first_number_label_;
  QLabel second_number_label_;

  CustomDialog enter_data_dialog_;

 private:
  double first_number_ = 0;
  double second_number_ = 0;
};

#endif  // MAINWINDOW_H_
