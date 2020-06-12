#ifndef __TRAINZEX__CORE__TYPES__H
#define __TRAINZEX__CORE__TYPES__H

namespace TrainzEx {
	//
	// Simplifying the data type mess...
	//
	using Int8		= char;
	using UInt8		= unsigned char;
	using In16		= short;
	using UInt16	= unsigned short;
	using Int32		= long;
	using UInt32	= unsigned long;
	using Int64		= long long;
	using UInt64	= unsigned long long;
	using Int		= Int64;
	using UInt		= UInt64;
	
	//
	// Instead of some bool value its often better to get some more information
	// about the result of a function. As TrainzEx is not using any exceptions
	// (the author doesn't likes them), we need some own type to give all information
	// needed.
	//
	enum class Result {
		Null		= 0,		// A value is not initialized
		OK			= 1,		// No error, function executed as it should do
		Error		= 2,		// An error occurred that made the function not work as expected
		NotFound	= 3,		// Some file or other data needed wasn't found
		Yes			= 4,		// Helpful for user interactions and/or windows
		No			= 5,		// Helpful for user interactions and/or windows
		Cancel		= 6,		// Helpful for user interactions and/or windows
		Exit		= 7,		// Helpful for user interactions and/or windows
		Stop		= 8			// Some loop or some thread was stopped
	};
};

#endif