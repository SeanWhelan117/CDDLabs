#include <iostream>
#include <thread>
#include <vector>
#include <memory>
#include <random>
#include "SafeBuffer.h"


static const int num_threads = 100;
const int size=20;

int count = 0;

std::random_device rd;
std::uniform_real_distribution<double> delay(0, 1);
std::uniform_int_distribution<int> dist(0, 25);
std::mt19937 gen(rd());


/*! \fn producer
    \brief Creates events and adds them to buffer
*/

void producer(std::shared_ptr<SafeBuffer<char>> theBuffer, int numLoops)
{

  for(int i=0;i<numLoops;++i)
    {
    //Produce event and add to buffer
      char item = 'a' + dist(gen);

      theBuffer->put(item);
	
      //theBuffer.put(e);
      std::cout << "added this to buffer " << item << std::endl;
      std::this_thread::sleep_for(std::chrono::duration<double>(delay(gen)));
	
    }
  theBuffer->put('X');

}

/*! \fn consumer
    \brief Takes events from buffer and consumes them
*/

void consumer(std::shared_ptr<SafeBuffer<char>> theBuffer)
{
  int amount = 0;

  while (true)
    {
      char item = theBuffer->get();
      amount++;

      if (item == 'X')
	{
	  count += amount;
	  std::cout << "exit thread: Reached" << std::endl;
	  break;
	}
      std::this_thread::sleep_for(std::chrono::duration<double>(delay(gen)));
    }
}

int main(void)
{
  std::vector<std::thread> prodThreads(num_threads);
  std::vector<std::thread> consThreads(num_threads);
  
  // std::vector<std::thread> vt(num_threads);
  // std::shared_ptr<SafeBuffer<std::shared_ptr<Event>> aBuffer( new Buffer<shared_ptr Event>(size));
  std::shared_ptr<SafeBuffer<char>> aBuffer(new SafeBuffer<char>(size));
  
  /**< Launch the threads  */
  int i=0;
  for(std::thread& t: prodThreads)
    {
    t=std::thread(producer ,aBuffer, 10);
    }
  for(std::thread& t : consThreads)
    {
      t = std::thread(consumer, aBuffer);
    }


  /**< Join the threads with the main thread */


  for (auto& v : prodThreads)
    {
      v.join();
    }
  for (auto& v : consThreads)
    {
      v.join();
    }
  std::cout << "Count = " << count << std::endl;
  std::cout <<"test" << std::endl; // wouldnt run without this change, Leo's Idea
  return 0;
}
