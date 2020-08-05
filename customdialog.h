#ifndef CUSTOMDIALOG_H_
#define CUSTOMDIALOG_H_

#include <QDialog>
#include <QDialogButtonBox>
#include <QDoubleValidator>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>

class CustomDialog : public QDialog {
  Q_OBJECT

 public:
  explicit CustomDialog(QWidget* parent = nullptr);
  ~CustomDialog() override = default;

  void accept() override;
  void reject() override;

  double GetFirstNumber() const;
  double GetSecondNumber() const;

  void ClearTextFields();

 private:
  QVBoxLayout layout_;
  QDialogButtonBox dialog_buttons_;

  QLabel first_number_label_;
  QLabel second_number_label_;
  QLineEdit first_number_text_;
  QLineEdit second_number_text_;
  QDoubleValidator double_validator_;

 private:
  double first_number_ = 0;
  double second_number_ = 0;
};

#endif  // CUSTOMDIALOG_H_
