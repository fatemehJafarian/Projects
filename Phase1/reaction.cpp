#include "reaction.hpp"

Reaction::Reaction()
{
	user = new User();
}

string Reaction::convert_int_to_string(int num)
{
	stringstream help;
	help << num;
	string result = help.str();
	return result;
}

Reaction* Reaction::check_reaction(string text_id)
{
	if (text_id == id)
		return this;
	for (int i = 0 ; i < replies.size() ; i++)
	{
		if (check_reaction(text_id))
			return check_reaction(text_id);
	}
	return NULL;
}