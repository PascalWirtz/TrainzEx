#ifndef __TRAINZEX__CORE__MEMORY__H
#define __TRAINZEX__CORE__MEMORY__H

namespace TrainzEx {
	class Context;

	//
	// Most of the resources are handled by the host process.
	// The Memory-Module offers an interface to allocate and free memory
	// inside the host process' heap.
	// Each plugin has it's own personal memory module.
	// Plugins don't need to allocate their memory by use of this module,
	// but it offers the advantage of automatic cleanup of all allocated memory
	// when the module is destroyed.
	//
	// This class is an interface class to the built in functions inside the host
	// application. When creating an instance of TrainzEx::Context and instance of
	// TrainzEx::Memory is automatically created within the Context.
	// See TrainzEx::Context for more details.
	//	
	class TrainzExCoreAPI Memory {
		friend class Context;

	private:
		//
		// Plugins can't construct the module by themselves. They are constructed automatically by the host process.
		// Plugins can access it via a TrainzEx::Context instance.
		//
		Memory() noexcept;					
		
		//
		// Plugins can't destroy the module by themselves. They are destroyed automatically by the host process.
		// Once the Memory Module gets destroyed it will clean all memory that wasn't cleared automatically.
		//
		~Memory() noexcept;

	public:
		//
		// Copy constructor
		//
		Memory(const Memory& m) noexcept;					
		
		//
		// 	Move constructor
		//
		Memory(Memory&& m) noexcept;

	public:
		//
		// Returns whether the Memory-Module is available.
		//
		bool IsAvailable(void) noexcept;	
		
		// Allocates memory of given size in the process heap and returns a pointer to its location.
		// If iSize is negative, the function will fail.
		// If any error occurres Alloc returns nullptr.
		void* Alloc(Int iSize) noexcept;
		
		// Reallocates the given memory block to the given size and returns a pointer to its location.
		// If iSize is a negative value its sibtracted from the given memory blocks size.
		// If the given memory block is invalid, ReAlloc allocates new memory of the given size.
		// If any error occurres ReAlloc returns nullptr.
		void* ReAlloc(void* pMemory, Int iSize) noexcept;

		// If the given memory block is valid Free will clear and release the memory block.
		// Returns Result::OK if the memory block was cleared successfully.
		Result Free(void* pMemory) noexcept;

		// Validates if the given memory block is allocated using the memory module.
		// Returns Result::OK if the memory block is valid.
		// Returns Result::Error if pMemory is a nullptr.
		// If pMemory is not nullptr but the it wasn't allocated by the memory module,
		// Validate returns Result::NotFound.
		Result Validate(void* pMemory) noexcept;

		// Returns the size of the given memory block.
		// If the block isn't allocated by the memory module, pMemory is nullptr or any other error
		// occurres, GetSíze returns -1.
		Int GetSize(void* pMemory) noexcept;
	};
};

#endif