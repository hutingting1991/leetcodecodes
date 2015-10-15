/**********************************************
* \version   0.0.1
* \author    Hu Tingting
* \created   20150101
* \modified  20151015
* \brief:
* Contact:   hutingting92@gmail.com
* Note:
**********************************************/
#include<algorithm>
#include "engine.h"

#define MATCH(a, b) {\
    reporter.MatchEvent(a,b); \
};


void MatchEngine::LimitOrder(int direction, long price, long vol)
{
	// this is where you should handle the incoming orders

	// remember, whenever the matchengine makes an order match, you should
	// use the MATCH( PRICE, VOL ) macro to report the order execution.
	// e.g the new order is a Buy order with price 100 and vol 120, current price
	// level has two counterpart orders (SELL order) as vol 20 and 80,
	// then you will make two mathes:
	// MATCH(100, 20)
	// MATCH(100, 80)
	if (direction == BUY){
		if (price > -1 && price < MinSellerPrice){
			LimitOrderBook[price].push(vol);
			if (price > MaxBuyerPrice)
				MaxBuyerPrice = price;			
		}
		else if (price < MAXPRICE){
			long cur = MinSellerPrice;
			while (vol > 0 && cur < price + 1){
				long tmp = LimitOrderBook[cur].front();
				MATCH(cur, std::min(vol, tmp));
				LimitOrderBook[cur].front() -= vol;
				vol -= tmp;
				if (LimitOrderBook[cur].front() < 1)
					LimitOrderBook[cur].pop();
				while (cur < MAXPRICE && LimitOrderBook[cur].empty())
					cur++;
			}
			if (vol > 0){
				LimitOrderBook[price].push(vol);
				MaxBuyerPrice = price;
			}
			MinSellerPrice = cur;
		}
	}
	else if (direction == SELL){
		if (price < MAXPRICE && price > MaxBuyerPrice){
			LimitOrderBook[price].push(vol);
			if (price < MinSellerPrice)
				MinSellerPrice = price;
		}
		else if (price > -1 && price < MaxBuyerPrice){
			long cur = MaxBuyerPrice;
			while (vol > 0 && cur > price - 1){
				long tmp = LimitOrderBook[cur].front();
				MATCH(cur, std::min(vol, tmp));				
				LimitOrderBook[cur].front() -= vol;
				vol -= tmp;
				if (LimitOrderBook[cur].front() < 1)
					LimitOrderBook[cur].pop();
				while (cur > -1 && LimitOrderBook[cur].empty())
					cur--;
			}
			if (vol > 0){
				LimitOrderBook[price].push(vol);
				MinSellerPrice = price;
			}
			MaxBuyerPrice = cur;
		}
	}
}

