//
// Thread.hh for l in /home/jonathan/Documents/TP/thread_c++
//
// Made by jonathan
// Login   <jonathan@epitech.net>
//
// Started on  Wed Apr 16 10:51:41 2014 jonathan
// Last update Wed Apr 16 14:14:32 2014 jonathan
//

#ifndef _ITHREAD_H_
# define _ITHREAD_H_

namespace Thread
{
  class IThread
  {
  public:
    enum ThreadState
      {
	STOP,
	RUN,
	DEAD
      };

  public:
    virtual ~IThread() {};

    virtual bool start(void *(*startRoutine)(void *), void*) = 0;
    virtual void wait() = 0;
    virtual ThreadState	getState() const = 0;
  };
}


#endif /* _THREAD_H_ */
