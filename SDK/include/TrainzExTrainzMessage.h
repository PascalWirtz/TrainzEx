#ifndef __TRAINZEX__CORE__TRAINZMESSAGE__H
#define __TRAINZEX__CORE__TRAINZMESSAGE__H

namespace TrainzEx {
	//
	// TrainzMessage is a smaller version of the Trainz ingame Message class.
	// It contains the main parts of every Trainz Message:
	// A major and a minor string.
	//
	// The major string is oftenly used as some kind of category or identifier.
	// Whereas the minor string contains more detailed information about the message itself.
	// Also the major string is oftenly way smaller than the minor string.
	// Therefore that major string here is capable of storing 128 characters and the minor string is
	// capable of storing 4096 characters, both including the null terminator.
	//
	// At this point its not possible to detect the sender and/or destination of a given message.
	// The best way, that is anyway recommended, is to create an ingame library, that is build to send
	// and receive predefined messages. This library could then parse and pack the minor string with
	// all information needed.
	//
	class TrainzExCoreAPI TrainzMessage {
	private:
		char			m_acMajor[128];			// Contains the major string of a trainz message
		char			m_acMinor[4096];		// Contains the minor string of a trainz message

	public:
		//
		// Default Constructor
		//
		TrainzMessage() noexcept;

		//
		// Overloaded Constructor
		// It will fill acMajor and acMinor automatically with the given strings.
		//
		TrainzMessage(const char* pcMajor, const char* pcMinor)	noexcept;

		//
		// Copy Constructor
		//
		TrainzMessage(const TrainzMessage& msg) noexcept;

		//
		// Move Constructor
		//
		TrainzMessage(TrainzMessage&& msg) noexcept;

		//
		// Default Destructor
		//
		~TrainzMessage() noexcept;

	public:
		// 
		// Returns a const pointer to acMajor
		//
		const char* Major(void) const noexcept;

		//
		// Returns a const pointer to acMinor
		//
		const char* Minor(void) const noexcept;

		//
		// Fills acMajor with the given string
		//
		void Major(const char* pcMajor) noexcept;

		//
		// Fills acMinor with the given string
		//
		void Minor(const char* pcMinor) noexcept;
	};
};

#endif