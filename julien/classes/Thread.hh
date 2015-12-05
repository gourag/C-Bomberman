//
// Thread.hh for  in /home/jonathan/Documents/TP/thread_c++
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Wed Apr 16 11:13:20 2014 jonathan
// Last update Wed Apr 16 14:16:20 2014 jonathan
//

#ifndef _THREAD_H_
# define _THREAD_H_

#include <pthread.h>
#include <signal.h>
#include "IThread.hh"

namespace Thread
{
  class Thread : public virtual IThread
  {
  private:
    Thread(const Thread &old);
    Thread operator=(const Thread &old);

    pthread_t		_thread;
    Thread::IThread::ThreadState	_state;
  public:
    Thread();
    virtual ~Thread();

    bool	start(void *(*startRoutine)(void *), void*);
    void	wait();
    Thread::IThread::ThreadState	getState() const;
  };
}


#endif /* _THREAD_H_ */
