#include "customdialog.h"

CustomDialog::CustomDialog(QWidget* parent)
    : QDialog(parent),
      layout_(),
      dialog_buttons_(QDialogButtonBox::Ok),
      first_number_label_("Enter first number: "),
      second_number_label_("Enter second number: "),
      first_number_text_(),
      second_number_text_(),
      double_validator_() {
  setLayout(&layout_);

  connect(&dialog_buttons_, &QDialogButtonBox::accepted, this,
          &QDialog::accept);

  layout_.addWidget(&first_number_label_);
  layout_.addWidget(&first_number_text_);
  layout_.addWidget(&second_number_label_);
  layout_.addWidget(&second_number_text_);
  layout_.addWidget(&dialog_buttons_);

  first_number_text_.setValidator(&double_validator_);
  second_number_text_.setValidator(&double_validator_);

  setWindowTitle("Enter data");
  setSizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
}

void CustomDialog::accept() {
  first_number_ = first_number_text_.text().toDouble();
  second_number_ = second_number_text_.text().toDouble();
  return QDialog::accept();
}

void CustomDialog::reject() {
  ClearTextFields();
  first_number_text_.setFocus();
  return QDialog::reject();
}

double CustomDialog::GetFirstNumber() const {
  return first_number_;
}

double CustomDialog::GetSecondNumber() const {
  return second_number_;
}

void CustomDialog::ClearTextFields() {
  first_number_text_.clear();
  second_number_text_.clear();
}
