template <typename IterType, typename ValType>
IterType find(IterType beg, IterType end, const ValType &val)
{
	while(beg != end)
	{
		if(*beg == val) break;
		++beg;
	}
	return beg;
}
