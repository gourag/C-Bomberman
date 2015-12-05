//
// Thread.cpp for  in /home/jonathan/Documents/TP/thread_c++
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Wed Apr 16 11:14:38 2014 jonathan
// Last update Fri May  9 14:38:58 2014 jonathan
//

#include "Thread.hh"

Thread::Thread::Thread()
{
  _state = IThread::STOP;
}
Thread::Thread::~Thread()
{
}
bool	Thread::Thread::start(void *(*startRoutine)(void *), void *arg)
{
  if (!pthread_create(&_thread, NULL, startRoutine, arg))
    {
      _state = IThread::RUN;
      return true;
    }
  return false;
}
void	Thread::Thread::wait()
{
  pthread_join(_thread, NULL);
}
Thread::IThread::ThreadState	Thread::Thread::getState() const
{
  if (pthread_kill(_thread, 0) != 0)
    return IThread::DEAD;
  return _state;
}
