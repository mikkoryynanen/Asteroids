class Stats
{
public:
	static Stats LoadStats()
	{
		Stats s;
		s.MovementSpeed = 350.f;
		return s;
	}

	float MovementSpeed = 0.f;

private:
};