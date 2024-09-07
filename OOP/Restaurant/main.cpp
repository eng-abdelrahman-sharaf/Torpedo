//#include "restaurant.h"
//#include "dish.h"
//
//int main() {
//	Restaurant restaurant("Abdo's Startup :)");
//
//	restaurant.requestDishes();
//	cout << "You have to pay " << restaurant.getOrderPrice();
//}


// no need of creating alot of database connectors for every obeject
class DBConnector {
	private:
		//static means that is common with all instances it's not connected to any object but connected to the class => class.staticMethod
		static DBConnector* db;
		//will not be used to get your initialize the class
		DBConnector() {
			db = 0;
			/*connect to db*/
		}
	public:
		static DBConnector* getsingletonInstance(){
			if (DBConnector::db == 0) db = new DBConnector();
			return db;
		}

};

class A {
	DBConnector db;
};


class B {
	DBConnector db;
};