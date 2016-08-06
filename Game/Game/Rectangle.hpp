#ifndef ___Class_Rectangle
#define ___Class_Rectangle

#include "Size.hpp"

namespace Utility {

	/**
	 * 長方形クラス
	 */
	class Rectangle {
	protected:
		Size<double> size;

	public:
		Rectangle(const Size<double>& size = Size<double>(0.0, 0.0));

		/**
		 * アクセッサ
		 */
		const Size<double>& getSize(void) const;
		virtual void setSize(const Size<double>& size);
	};

}

inline const Size<double>& Utility::Rectangle::getSize(void) const
{
	return size;
}

#endif

