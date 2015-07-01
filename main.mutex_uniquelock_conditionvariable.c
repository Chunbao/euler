/**
 * Semaphore example, written in C++ May 4, 2014
 * Compiled on OSX 10.9, using:
 * g++ -std=c++11 semaphore.cpp
 **/
 
#include <iostream>      
#include <thread>        
#include <mutex>         
#include <condition_variable>
 
// cnjiand, std::*lock
// lock_guard is locked only once on construction and unlocked on destruction.
// unique_lock can lock and unlock. Ues to SYNCHRONIZE threads.
// lock_guard is a restricted version with a limited interface.

std::mutex mtx;             // mutex for critical section
std::condition_variable cv; // condition variable for critical section  
bool ready = false;         // Tell threads to run
int current = 0;            // current count
 
/* Prints the thread id / max number of threads */
void print_num(int num, int max) {
 
  std::unique_lock<std::mutex> lck(mtx);

  // cnjiand: used to synchronize threads
  while(num != current || !ready){ cv.wait(lck); }
  current++;
  std::cout << "Thread: ";
  std::cout << num + 1 << " / " << max;
  std::cout << " current count is: ";
  std::cout << current << std::endl;
  
  /* Notify next threads to check if it is their turn */
  cv.notify_all(); 
}
 
/* Changes ready to true, and begins the threads printing */
void run(){
  std::unique_lock<std::mutex> lck(mtx);
  ready = true;
  cv.notify_all();
}
 
int main (){
 
  int threadnum = 15;
  std::thread threads[15];
 
  /* spawn threadnum threads */
  for (int id = 0; id < threadnum; id++)
    threads[id] = std::thread(print_num, id, threadnum);
 
  std::cout << "\nRunning " << threadnum;
  std::cout << " in parallel: \n" << std::endl;
 
  run(); // Allows threads to run
 
  /* Merge all threads to the main thread */
  for(int id = 0; id < threadnum; id++)
    threads[id].join();
 
  std::cout << "\nCompleted semaphore example!\n";
  std::cout << std::endl;
 
  return 0;
}
