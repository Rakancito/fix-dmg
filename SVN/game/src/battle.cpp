// Search

int battle_melee_attack(LPCHARACTER ch, LPCHARACTER victim)
{

// Add after

	if(ch->IsPC())
	{
		if (test_server&&ch->IsPC())
			ch->ChatPacket(CHAT_TYPE_INFO, "Melee Attack: %d", get_dword_time() - ch->GetLastAttackTime());
		if (ch->IsRiding())
		{
			bool bAttacking = (get_dword_time() - ch->GetLastAttackTime()) < 800;
			if (!bAttacking)
				return BATTLE_NONE;
		}
		else
		{
			bool bAttacking = (get_dword_time() - ch->GetLastAttackTime()) < 750;
			if (!bAttacking)
				return BATTLE_NONE;

		}
		if (!battle_distance_valid(ch, victim))
			return BATTLE_NONE;
	}

// Search

int battle_hit(LPCHARACTER pkAttacker, LPCHARACTER pkVictim, int & iRetDam)
{

// Add after

	if(pkAttacker->IsPC())
	{
		if (test_server&&pkAttacker->IsPC())
			pkAttacker->ChatPacket(CHAT_TYPE_INFO, "Battle_Hit: %d", get_dword_time() - pkAttacker->GetLastAttackTime());
		if (pkAttacker->IsRiding())
		{
			bool bAttacking = (get_dword_time() - pkAttacker->GetLastAttackTime()) < 800;
			if (!bAttacking)
				return BATTLE_NONE;
		}
		else
		{
			bool bAttacking = (get_dword_time() - pkAttacker->GetLastAttackTime()) < 750;
			if (!bAttacking)
				return BATTLE_NONE;
		}
		if (!battle_distance_valid(pkAttacker, pkVictim))
			return BATTLE_NONE;
	}
