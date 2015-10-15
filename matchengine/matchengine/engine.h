/**********************************************
* \version   0.0.1
* \author    Hu Tingting
* \created   20150101
* \modified  20151015
* \brief:
* Contact:   hutingting92@gmail.com
* Note:
**********************************************/

#ifndef _engine_H_lSpJLFkhxa_
#define _engine_H_lSpJLFkhxa_

#include <iostream>
#include <string>
#include <vector>
#include <queue>

#define  BUY  0
#define  SELL 1
#define  MAXPRICE 201	

//! this is the matchengine
class MatchEngine {
protected:
	// this is where you should put your data structure
	// holding the limit order book; You could design the limit
	// order book as you wish.
	// NOTE that the limit order book has price range of 100-200
	std::queue<long> LimitOrderBook[MAXPRICE];
	long MaxBuyerPrice = 0;
	long MinSellerPrice = MAXPRICE;

public:
	// LimitOrder handles the incoming order, direction could
	// be BUY/SELL, price and volume are long integer
	void LimitOrder(int direction, long price, long vol);

};


//! this is the class used in test, you can safely ignore it.
class Reporter{
private:
	struct EVENT{
		long price;
		long vol;
	};
public:
	std::vector<EVENT> events;
public:
	int num_events;
	long total_price;

	void MatchEvent(long price, long vol){
		EVENT event;
		event.price = price;
		event.vol = vol;
		++num_events;
		total_price += price;
		events.push_back(event);
	}

	void Clear(){
		num_events = 0;
		total_price = 0;
	}

};

extern Reporter reporter;

#endif
