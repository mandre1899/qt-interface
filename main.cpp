#include <QApplication>
#include <QCheckBox>
#include <QFormLayout>
#include <QFrame>
#include <QGraphicsDropShadowEffect>
#include <QLabel>
#include <QLineEdit>
#include <QMainWindow>
#include <QPushButton>
#include <QRegularExpression>
#include <QScrollArea>
#include <QStyle>
#include <QVBoxLayout>
#include <iostream>

namespace {

QLineEdit *createField(const QString &placeholder, bool password = false) {
  auto *field = new QLineEdit;
  field->setPlaceholderText(placeholder);
  field->setMinimumHeight(46);
  field->setClearButtonEnabled(!password);
  if (password)
    field->setEchoMode(QLineEdit::Password);
  return field;
}

QLabel *createFieldLabel(const QString &text) {
  auto *label = new QLabel(text);
  label->setObjectName("fieldLabel");
  return label;
}

} // namespace

int main(int argc, char *argv[]) {
  QApplication app(argc, argv);
  app.setApplicationName("Create Account");
  app.setStyleSheet(R"(
        QWidget {
            color: #1d1d1f;
            font-family: "SF Pro Text", "Helvetica Neue", Arial;
            font-size: 14px;
        }
        QWidget#page {
            background: #f5f5f7;
        }
        QFrame#card {
            background: #ffffff;
            border: 1px solid #e5e5e7;
            border-radius: 18px;
        }
        QLabel#brandMark {
            color: white;
            background: #0071e3;
            border-radius: 23px;
            font-size: 21px;
            font-weight: 600;
        }
        QLabel#title {
            font-size: 28px;
            font-weight: 600;
        }
        QLabel#subtitle {
            color: #6e6e73;
            font-size: 14px;
        }
        QLabel#fieldLabel {
            font-size: 13px;
            font-weight: 600;
        }
        QLineEdit {
            color: #1d1d1f;
            background: #ffffff;
            border: 1px solid #d2d2d7;
            border-radius: 10px;
            padding: 0 13px;
            selection-background-color: #0071e3;
        }
        QLineEdit:hover {
            border-color: #a1a1a6;
        }
        QLineEdit:focus {
            border: 2px solid #0071e3;
            padding: 0 12px;
        }
        QLineEdit[invalid="true"] {
            border: 2px solid #d70015;
            padding: 0 12px;
        }
        QLineEdit::placeholder {
            color: #86868b;
        }
        QCheckBox {
            color: #515154;
            spacing: 9px;
        }
        QCheckBox::indicator {
            width: 17px;
            height: 17px;
            border: 1px solid #b8b8bd;
            border-radius: 5px;
            background: white;
        }
        QCheckBox::indicator:checked {
            background: #0071e3;
            border-color: #0071e3;
            image: url(:/qt-project.org/styles/commonstyle/images/standardbutton-apply-16.png);
        }
        QPushButton#createButton {
            color: white;
            background: #0071e3;
            border: none;
            border-radius: 10px;
            min-height: 46px;
            font-weight: 600;
        }
        QPushButton#createButton:hover {
            background: #0077ed;
        }
        QPushButton#createButton:pressed {
            background: #0068d1;
        }
        QPushButton#createButton:disabled {
            background: #9ccbf5;
        }
        QLabel#error {
            color: #d70015;
            font-size: 12px;
        }
        QLabel#success {
            color: #217a3c;
            background: #eef8f0;
            border: 1px solid #c7e6ce;
            border-radius: 9px;
            padding: 10px 12px;
        }
        QLabel#footer {
            color: #6e6e73;
        }
        QLabel#footer a {
            color: #0066cc;
            text-decoration: none;
        }
        QScrollArea {
            border: none;
            background: transparent;
        }
        QScrollBar:vertical {
            width: 8px;
            background: transparent;
        }
        QScrollBar::handle:vertical {
            min-height: 30px;
            background: #c7c7cc;
            border-radius: 4px;
        }
        QScrollBar::add-line:vertical, QScrollBar::sub-line:vertical {
            height: 0;
        }
    )");

  QMainWindow window;
  window.setWindowTitle("Andre ERP");
  window.setMinimumSize(420, 620);
  window.resize(760, 820);

  auto *scrollArea = new QScrollArea;
  scrollArea->setWidgetResizable(true);
  scrollArea->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

  auto *page = new QWidget;
  page->setObjectName("page");
  auto *pageLayout = new QVBoxLayout(page);
  pageLayout->setContentsMargins(28, 38, 28, 38);
  pageLayout->addStretch();

  auto *card = new QFrame;
  card->setObjectName("card");
  card->setMaximumWidth(480);
  auto *shadow = new QGraphicsDropShadowEffect(card);
  shadow->setBlurRadius(35);
  shadow->setOffset(0, 10);
  shadow->setColor(QColor(0, 0, 0, 28));
  card->setGraphicsEffect(shadow);

  auto *cardLayout = new QVBoxLayout(card);
  cardLayout->setContentsMargins(42, 38, 42, 34);
  cardLayout->setSpacing(0);

  auto *brandMark = new QLabel("A");
  brandMark->setObjectName("brandMark");
  brandMark->setAlignment(Qt::AlignCenter);
  brandMark->setFixedSize(46, 46);
  cardLayout->addWidget(brandMark, 0, Qt::AlignHCenter);
  cardLayout->addSpacing(19);

  auto *title = new QLabel("Create your account");
  title->setObjectName("title");
  title->setAlignment(Qt::AlignCenter);
  cardLayout->addWidget(title);
  cardLayout->addSpacing(8);

  auto *subtitle = new QLabel("One account. A simpler way to get started.");
  subtitle->setObjectName("subtitle");
  subtitle->setAlignment(Qt::AlignCenter);
  subtitle->setWordWrap(true);
  cardLayout->addWidget(subtitle);
  cardLayout->addSpacing(28);

  auto *nameField = createField("Alex Morgan");
  auto *emailField = createField("name@example.com");
  auto *passwordField = createField("At least 8 characters", true);
  auto *confirmField = createField("Enter your password again", true);

  auto *formLayout = new QFormLayout;
  formLayout->setContentsMargins(0, 0, 0, 0);
  formLayout->setVerticalSpacing(9);
  formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
  formLayout->setRowWrapPolicy(QFormLayout::WrapAllRows);
  formLayout->addRow(createFieldLabel("Full name"), nameField);
  formLayout->addRow(createFieldLabel("Email address"), emailField);
  formLayout->addRow(createFieldLabel("Password"), passwordField);
  formLayout->addRow(createFieldLabel("Confirm password"), confirmField);
  cardLayout->addLayout(formLayout);
  cardLayout->addSpacing(13);

  auto *terms =
      new QCheckBox("I agree to the Terms of Service and Privacy Policy.");
  cardLayout->addWidget(terms);
  cardLayout->addSpacing(10);

  auto *message = new QLabel;
  message->setObjectName("error");
  message->setWordWrap(true);
  message->hide();
  cardLayout->addWidget(message);

  auto *createButton = new QPushButton("Create account");
  createButton->setObjectName("createButton");
  createButton->setCursor(Qt::PointingHandCursor);
  createButton->setDefault(true);
  cardLayout->addSpacing(10);
  cardLayout->addWidget(createButton);
  cardLayout->addSpacing(22);

  auto *footer =
      new QLabel("Already have an account? <a href=\"signin\">Sign in</a>");
  footer->setObjectName("footer");
  footer->setAlignment(Qt::AlignCenter);
  cardLayout->addWidget(footer);

  pageLayout->addWidget(card, 0, Qt::AlignHCenter);
  pageLayout->addStretch();
  scrollArea->setWidget(page);
  window.setCentralWidget(scrollArea);

  const auto setInvalid = [](QLineEdit *field, bool invalid) {
    field->setProperty("invalid", invalid);
    field->style()->unpolish(field);
    field->style()->polish(field);
  };

  QObject::connect(createButton, &QPushButton::clicked, [&] {
    const QRegularExpression emailPattern(R"(^[^\s@]+@[^\s@]+\.[^\s@]+$)");
    const bool nameValid = nameField->text().trimmed().size() >= 2;
    const bool emailValid =
        emailPattern.match(emailField->text().trimmed()).hasMatch();
    const bool passwordValid = passwordField->text().size() >= 8;
    const bool confirmationValid =
        !confirmField->text().isEmpty() &&
        confirmField->text() == passwordField->text();

    setInvalid(nameField, !nameValid);
    setInvalid(emailField, !emailValid);
    setInvalid(passwordField, !passwordValid);
    setInvalid(confirmField, !confirmationValid);

    message->setObjectName("error");
    if (!nameValid)
      message->setText("Enter your full name.");
    else if (!emailValid)
      message->setText("Enter a valid email address.");
    else if (!passwordValid)
      message->setText("Your password must contain at least 8 characters.");
    else if (!confirmationValid)
      message->setText("Your passwords do not match.");
    else if (!terms->isChecked())
      message->setText(
          "Please agree to the Terms of Service and Privacy Policy.");
    else {
      message->setObjectName("success");
      message->setText("Your account is ready. Welcome, " +
                       nameField->text().trimmed() + "!");
    }
    std::cout << "Test: " << nameField->text().toStdString() << ", "
              << emailField->text().toStdString() << ", "
              << passwordField->text().toStdString() << std::endl;
    message->style()->unpolish(message);
    message->style()->polish(message);
    message->show();
  });

  const auto clearError = [&](const QString &) {
    auto *field = qobject_cast<QLineEdit *>(QApplication::focusWidget());
    if (field)
      setInvalid(field, false);
    if (message->objectName() == "error")
      message->hide();
  };
  QObject::connect(nameField, &QLineEdit::textChanged, clearError);
  QObject::connect(emailField, &QLineEdit::textChanged, clearError);
  QObject::connect(passwordField, &QLineEdit::textChanged, clearError);
  QObject::connect(confirmField, &QLineEdit::textChanged, clearError);

  window.show();
  return app.exec();
}
