#include <QApplication>
#include "my_dialog.h"

#include <boost/graph/adjacency_list.hpp>

///C++14 and Boost
auto f() noexcept
{
  boost::adjacency_list<> g;
  boost::add_vertex(g);
  return boost::num_vertices(g);
}


int main(int argc, char *argv[])
{
  QApplication a(argc, argv);
  if (f() != 1) return 1;
  my_dialog d;
  d.show();
  return a.exec();
}
