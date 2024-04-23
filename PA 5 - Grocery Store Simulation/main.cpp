#include "data.hpp"
#include "queue.hpp"
#include "queueNode.hpp"
#include "testCases.hpp"

int main()
{
	// Declare required variables
	int menuChoice = -1;

	// Declare required variables
	Queue* testLane = new Queue();
	Queue expressLane, normalLane;
	int expressArrivalTime = -1, expressServiceTime = -1, normalArrivalTime = -1, normalServiceTime = -1,
		totalTime = -1, minutesToRun = -1, customerNumber = 1;

	// Prompt user for their choice
	std::cout << "Do you want to run test cases (1) or the simulation (2)? " << std::endl;
	std::cin >> menuChoice;

	switch (menuChoice)
	{
	case 1:
		testEnqueueNoNode(testLane);
		testEnqueueOneNode(testLane);
		testDequeueTwoNode(testLane);
		testDequeueOneNode(testLane);

		runSimulationFullDay();

		break;
	case 2:
		// Generate a random number seed
		srand((unsigned int)time(nullptr));

		// Generate starting random numbers for arrival and service times
		expressArrivalTime = rand() % 5 + 1;
		normalArrivalTime = rand() % 6 + 3;
		expressServiceTime = rand() % 5 + 1;
		normalServiceTime = rand() % 6 + 3;

		// Reset total time
		totalTime = 0;

		// Ask for simulation run length and validate it
		do
		{
			std::cout << "How long do you want to run the simulation for (in minutes)?" << std::endl;
			std::cin >> minutesToRun;
		} while (minutesToRun <= 0);

		// Run the simulation for the specified amount of time
		for (int minute = 0; minute < minutesToRun; minute++)
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

		break;
	default:
		std::cout << "Not a valid choice." << std::endl;

		break;
	}

	// Return success
	return 0;
}
