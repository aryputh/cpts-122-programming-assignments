#include "testCases.hpp"
#include "queue.hpp"
#include "data.hpp"

/*
*	Description: Enqueues a node into a queue with no nodes.
*	Date: 3/6/2024
*
*	Preconditions: None.
*	Postconditions: A node with the specified data is enqueued.
*/
void testEnqueueNoNode(Queue* testQueue)
{
	Data* newData = new Data(1, 5, 0);

	testQueue->enqueue(newData);

	std::cout << "Testing Lane (Enqueue first node):" << std::endl;
	testQueue->printQueue();
}

/*
*	Description: Enqueues a node into a queue with one nodes.
*	Date: 3/6/2024
*
*	Preconditions: None.
*	Postconditions: A node with the specified data is enqueued.
*/
void testEnqueueOneNode(Queue* testQueue)
{
	Data* newData = new Data(2, 6, 5);

	testQueue->enqueue(newData);

	std::cout << "Testing Lane (Enqueue second node):" << std::endl;
	testQueue->printQueue();
}

/*
*	Description: Dequeues a node from a queue with two nodes.
*	Date: 3/6/2024
*
*	Preconditions: None.
*	Postconditions: A node is dequeued.
*/
void testDequeueTwoNode(Queue* testQueue)
{
	testQueue->dequeue();

	std::cout << "Testing Lane (Dequeue second node):" << std::endl;
	testQueue->printQueue();
}

/*
*	Description: Dequeues a node from a queue with one nodes.
*	Date: 3/6/2024
*
*	Preconditions: None.
*	Postconditions: A node is dequeued.
*/
void testDequeueOneNode(Queue* testQueue)
{
	testQueue->dequeue();

	std::cout << "Testing Lane (Dequeue first node):" << std::endl;
	testQueue->printQueue();
}

/*
*	Description: Runs the simulation for a full day (1440 minutes).
*	Date: 3/6/2024
*
*	Preconditions: None.
*	Postconditions: The simulation is run for a full day.
*/
void runSimulationFullDay()
{
	// Declare required variables
	Queue expressLane, normalLane, testLane;
	int expressArrivalTime = -1, expressServiceTime = -1, normalArrivalTime = -1, normalServiceTime = -1,
		totalTime = -1, customerNumber = 1;

	// Generate a random number seed
	srand((unsigned int)time(nullptr));

	// Generate starting random numbers for arrival and service times
	expressArrivalTime = rand() % 5 + 1;
	normalArrivalTime = rand() % 6 + 3;
	expressServiceTime = rand() % 5 + 1;
	normalServiceTime = rand() % 6 + 3;

	// Reset total time
	totalTime = 0;

	// Run the simulation for the specified amount of time
	for (int minute = 0; minute < 1440; minute++)
	{
		// If arrival times are 0, add a customer into lane, and give them a service number
		if (expressArrivalTime == 0)
		{
			totalTime += expressServiceTime;

			// Set customer data values
			Data* newCustomer = new Data(customerNumber, expressServiceTime, totalTime);

			// Add the customer to the line
			expressLane.enqueue(newCustomer);

			// Generate a random service and arrival time
			expressServiceTime = rand() % 5 + 1;
			expressArrivalTime = rand() % 5 + 1;

			customerNumber++;

			// Display new customer details
			std::cout << "---------------------------------" << std::endl;
			std::cout << "New Express Customer Number: " << newCustomer->getCustomerNumber()
				<< " Service Time: " << newCustomer->getServiceTime()
				<< " Total time: " << newCustomer->getTotalTime() << std::endl;
		}

		if (normalArrivalTime == 0)
		{
			totalTime += normalServiceTime;

			// Set customer data values
			Data* newCustomer = new Data(customerNumber, normalServiceTime, totalTime);

			// Add the customer to the line
			normalLane.enqueue(newCustomer);

			// Generate a random service and arrival time
			normalServiceTime = rand() % 6 + 3;
			normalArrivalTime = rand() % 6 + 3;

			customerNumber++;

			// Display new customer details
			std::cout << "---------------------------------" << std::endl;
			std::cout << "New Normal Customer Number: " << newCustomer->getCustomerNumber()
				<< " Service Time: " << newCustomer->getServiceTime()
				<< " Total time: " << newCustomer->getTotalTime() << std::endl;
		}

		// Decrement service time
		if (!expressLane.isEmpty())
		{
			expressLane.getHead()->getData()->setServiceTime(expressLane.getHead()->getData()->getServiceTime() - 1);
		}

		if (!normalLane.isEmpty())
		{
			normalLane.getHead()->getData()->setServiceTime(normalLane.getHead()->getData()->getServiceTime() - 1);
		}

		// Print out both queues every 10 minutes
		if (minute % 10 == 0)
		{
			std::cout << "---------------------------------" << std::endl;
			std::cout << "---------------------------------" << std::endl;

			std::cout << "Current Minute: " << minute << std::endl;
			std::cout << "Express Lane:" << std::endl;
			expressLane.printQueue();

			std::cout << "Normal Lane:" << std::endl;
			normalLane.printQueue();

			std::cout << "---------------------------------" << std::endl;
			std::cout << "---------------------------------" << std::endl;
		}

		// Display customers are done checking out and dequeue them
		if (!expressLane.isEmpty() && expressLane.getHead()->getData()->getServiceTime() == 0)
		{
			// Dequeue them from the queue
			Data* customer = new Data(*expressLane.dequeue());

			if (customer != nullptr)
			{
				// Display done customer details
				std::cout << "---------------------------------" << std::endl;
				std::cout << "Done Normal Customer Number: " << customer->getCustomerNumber()
					<< " Service Time: " << customer->getServiceTime()
					<< " Total time: " << customer->getTotalTime() << std::endl;
			}

			// Delete them
			delete customer;
		}

		// Display customers are done checking out and dequeue them
		if (!normalLane.isEmpty() && normalLane.getHead()->getData()->getServiceTime() == 0)
		{
			// Dequeue them from the queue
			Data* customer = new Data(*normalLane.dequeue());

			if (customer != nullptr)
			{
				// Display done customer details
				std::cout << "---------------------------------" << std::endl;
				std::cout << "Done Normal Customer Number: " << customer->getCustomerNumber()
					<< " Service Time: " << customer->getServiceTime()
					<< " Total time: " << customer->getTotalTime() << std::endl;
			}

			// Delete them
			delete customer;
		}

		// Decrement service and arrival time for queues, and increment customer number
		expressArrivalTime--;
		normalArrivalTime--;

		// Reset customer number every day
		if (minute % 1440 == 0)
		{
			customerNumber = 1;
		}
	}
}
