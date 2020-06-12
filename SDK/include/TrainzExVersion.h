#ifndef __TRAINZEX__CORE__VERSION__H
#define __TRAINZEX__CORE__VERSION__H

namespace TrainzEx {
	//
	// The Version class is a wrapper for a 32 bit unsigned integer thats
	// low and high word separated give a version number.
	// You can either specifiy the low and high words or directly give
	// the corresponding combined 32 bit unsigned integer.
	//
	// uVersion represents the whole 32 bit unsigned integer,
	// uLow and uHigh represent the 16 bit unsigned low and high words.
	//
	// At this point Version overloads only a small set of assignment and logical operators.
	// This will be extended in the future.
	//
	class TrainzExCoreAPI Version {
	public:
		union {
			struct {
				UInt16		uHigh;
				UInt16		uLow;
			};
			UInt32			uVersion;
		};

	public:
		Version()										noexcept;
		Version(UInt32 _uVersion)						noexcept;
		Version(UInt16 _uHigh, UInt16 _uLow)			noexcept;
		Version(const Version& v)						noexcept;
		Version(Version&& v)							noexcept;
		~Version()										noexcept;

		Version&	operator=(const Version& v)			noexcept;
		Version&	operator=(Version&& v)				noexcept;
		bool		operator==(const Version& v) const	noexcept;
		bool		operator==(Version&& v) const		noexcept;
		bool		operator!=(const Version& v) const	noexcept;
		bool		operator!=(Version&& v) const		noexcept;
	};
};

#endif