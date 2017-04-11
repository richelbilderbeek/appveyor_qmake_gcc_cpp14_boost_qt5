#include "my_dialog.h"
#include "ui_my_dialog.h"

#include <fstream>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/local_time_adjustor.hpp>
#include <boost/date_time/c_local_time_adjustor.hpp>
#include <QTimer>

my_dialog::my_dialog(QWidget *parent) :
  QDialog(parent),
  ui(new Ui::my_dialog)
{
  ui->setupUi(this);
  QTimer * const timer(new QTimer(this));
  connect(
    timer,
    &QTimer::timeout,
    this,
    &my_dialog::close
  );
  timer->setInterval(1'000); //C++14 allows digit seperators
  timer->start();

  //Create a file to show the program is run
  {
    std::ofstream f("appveyor_qmake_gcc_cpp14_boost_qt5.txt");
    f << boost::posix_time::to_simple_string(
      boost::posix_time::ptime(
        boost::gregorian::day_clock::universal_day(),
        boost::posix_time::second_clock::universal_time().time_of_day()
      )
    ) << '\n';
  }
}

my_dialog::~my_dialog() noexcept
{
  delete ui;
}
