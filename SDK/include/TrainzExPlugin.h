#ifndef __TRAINZEX__CORE__PLUGIN__H
#define __TRAINZEX__CORE__PLUGIN__H

namespace TrainzEx {
	class Context;

	//
	// All plugins must inherit this class and implement all pure virtual functions.
	//
	// The host application is doing several security checks to ensure plugins are
	// not malicous and/or badly coded.
	//
	// If the host application detects unexpected behavior (from its own point of 'view')
	// it will immediately try to get rid of the plugin. If unloading attempts fail,
	// the application will force itself and all plugin threads to terminate.
	//
	// Its free to every plugin to use 3rd party libraries.
	//
	// Plugins are loaded into the host application but not into Trainz itself.
	// The host application will connect to trainz from outside via encrypted connection.
	// All data passes the host application and plugins are not able to call directly into
	// Trainz.
	//
	// Stability and security of the Trainz application and the user's data within the Trainz
	// application have highest priority. Therefore various plugin functionality might be limited
	// if the TrainzEx host application detects any abuse.
	//
	class TrainzExCoreAPI Plugin {
	public:
		//
		// Default Constructor
		// Plugins must implement it and call the base constructor.
		//
		Plugin() noexcept;

		//
		// Copy Constructor
		// Plugins must implement and call the base copy constructor.
		//
		Plugin(const Plugin& p) noexcept;

		//
		// Move Constructor
		// Plugins must implement it and call the base move constructor.
		//
		Plugin(Plugin&& p) noexcept;

		//
		// virtual Destructor
		//
		virtual ~Plugin() noexcept;

	public:
		//
		// Init is called once the plugin gets loaded into the host application.
		// The host application will forward any command line arguments to the plugins.
		// Like the classical main entry point function, there are argc and argv parameters.
		//
		virtual Result Init(Int32 argc, char* argv[]) noexcept = 0;

		//
		// OnTrainzMessage will be called once a message that meets one or more handlers added for the plugin
		// is send within the Trainz application.
		// See TrainzEx::TrainzMessage for further details.
		//
		virtual Result OnTrainzMessage(const TrainzMessage& Notify) noexcept = 0;

		//
		// Exit is called once the plugin gets unloaded.
		// Plugins don't need to call this method by themselves.
		//
		virtual void Exit(void) noexcept = 0;

	public:
		//
		// GetVersion must return a version object containing the version of the plugin.
		// The host application might use this information for updating or configuration purposes.
		//
		virtual Version GetVerion(void) const noexcept = 0;

		//
		// GetNamemust return the name of the plugin. It must be the same as the Dll's filename.
		// The host application might use this information for updating or configuration purposes.
		//
		virtual const char* GetName(void) const noexcept = 0;

		//
		// GetAuthor must return the name of the Author or an alias.
		// The host application might use this information for updating or configuration purposes.
		//
		virtual const char* GetAuthor(void) const noexcept = 0;
	};
};

#endif