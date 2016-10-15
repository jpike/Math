#pragma once

namespace MATH
{
    /// A mathematical angle, which exists between two lines with a common endpoint.
    /// @tparam ValueType - The underlying type for which to store angle values.
    template <typename ValueType>
    class Angle
    {
    public:
        // NESTED TYPES.
        /// A nested type to represent an angle value in radians,
        /// providing some type-checking.
        struct Radians
        {
            /// The angle value in radians.
            ValueType Value;

            explicit Radians(const ValueType value);
        };

        /// A nested type to represent an angle value in degrees,
        /// providing some type-checking.
        struct Degrees
        {
            /// The angle value in degrees.
            ValueType Value;

            explicit Degrees(const ValueType value);
        };

        // STATIC METHODS.
        static Radians DegreesToRadians(const Degrees degrees);
    };
    
    /// Constructor.
    /// @param[in]  value - The angle value, in radians.
    template <typename ValueType>
    Angle<ValueType>::Radians::Radians(const ValueType value) :
        Value(value)
    {}

    /// Constructor.
    /// @param[in]  value - The angle value, in degrees.
    template <typename ValueType>
    Angle<ValueType>::Degrees::Degrees(const ValueType value) :
        Value(value)
    {}

    /// Converts an angle value from degrees to radians.
    /// @param[in]  degrees - The angle value in degrees.
    /// @return The angle value in radians.
    template <typename ValueType>
    typename Angle<ValueType>::Radians Angle<ValueType>::DegreesToRadians(const typename Angle<ValueType>::Degrees degrees)
    {
        /// @todo   More precision for pi.
        const ValueType HALF_CIRCLE_IN_RADIANS = static_cast<ValueType>(3.14159);
        const ValueType HALF_CIRCLE_IN_DEGREES = static_cast<ValueType>(180);
        ValueType radians_value = degrees.Value * HALF_CIRCLE_IN_RADIANS / HALF_CIRCLE_IN_DEGREES;
        Radians radians(radians_value);
        return radians;
    }
}
