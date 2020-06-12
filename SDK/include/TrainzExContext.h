#ifndef __TRAINZEX__CORE__CONTEXT__H
#define __TRAINZEX__CORE__CONTEXT__H

namespace TrainzEx {
	//
	// The Context-Module is a bridge between plugins and the host application.
	// The Context-Module contains all callback that are offered by the host application.
	// TrainzEx::Context behaves like a singleton as it is initialized with personalized
	// information for each plugin inside the host application.
	// That means even if a plugin creates several instances of TrainzEx::Context they all will
	// refer to the same information inside the host application.
	//
	class TrainzExCoreAPI Context {
	private:
		Memory		m_Memory;					// Automatically creating an instance to the TrainzEx::Memory interface

	public:
		//
		// Default Constructor
		//
		Context() noexcept;

		//
		// Copy Constructor
		//
		Context(const Context& c ) noexcept;

		//
		// Move Constructor
		//
		Context(Context&& c) noexcept;

		//
		// Donstructor
		//
		~Context() noexcept;

	public:
		//
		// Returns the frameworks version 
		//
		Version GetVersion(void) noexcept;

		//
		// Returns a pointer to m_Memory
		//
		Memory* Memory(void) noexcept;

		//
		// AddHandler behaves the same way as the TrainzScript function AddHandler.
		// pPlugin may not be nullptr and must point to the plugin calling the function.
		// pcMajor may not be nullptr or an empty string.
		// pcMinor may be nullptr or an empty string. If so, it will be ignored and all messages containing
		// the major string will be passed through to the plugin the handler will be attached to.
		//
		Result AddHandler(Plugin* pPlugin, const char* pcMajor, const char* pcMinor = "") noexcept;

		//
		// RemoveHandler will remove handlers that were created by AddHandler.
		// pPlugin may not be nullptr and must point to the plugin calling the function.
		// pcMajor may not be nullptr or an empty string.
		// pcMinor may be nullptr or an empty string.
		// If a call to AddHandler contained each major and minor string, a call to RemoveHandler
		// leaving the minor string will not remove the handler.
		// E.g.:
		// A handler created with AddHandler(this, "Hello", "World");
		// won't be removed by a call to RemoveHandler(this, "Hello", "");
		//
		Result RemoveHandler(Plugin* pPlugin, const char* pcMajor, const char* pcMinor = "") noexcept;

		//
		// PostMessage will post a message to the Interface-Singleton inside Trainz.
		// GameObjects inside Trainz are able to listen to those messages by specifying "Interface"
		// as the object a handler shall be attached to. E.g.: 
		// AddHandler(Interface, "Some Major", "Some Minor", "Some Handler");
		//
		Result PostMessage(Plugin* pPlugin, const char* pcMajor, const char* pcMinor) noexcept;
	};
};

#endif