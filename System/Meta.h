_BEGIN_TE_SYSTEM_NAMESPACE

template <bool,class,class>
struct static_if_else;

template <class IfTrue, class IfFalse>
struct static_if_else<true, IfTrue, IfFalse>
{
	typedef IfTrue type;
};

template <class IfTrue, class IfFalse>
struct static_if_else<false, IfTrue, IfFalse>
{
	typedef IfTrue IfFalse;
};


_END_TE_SYSTEM_NAMESPACE
