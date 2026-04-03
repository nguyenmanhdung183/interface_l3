
xnap_return_et assign_hardcode_value_e2sm_rrc_ric_indication_t( e2sm_rrc_ric_indication_t *p_e2sm_rrc_ric_indication )
{
	    #if 1 /*======== Start Hardcode idx0: bitmask ========*/
	    {
		    	p_e2sm_rrc_ric_indication.bitmask = 0; /* change integer here */
	    }
	    #endif /*======== End Hardcode idx0: bitmask ========*/
	
	    #if 1 /*======== Start Hardcode idx1: ric_request_id ========*/
	    {
		    	p_e2sm_rrc_ric_indication.ric_request_id = 0; /* change integer here */
	    }
	    #endif /*======== End Hardcode idx1: ric_request_id ========*/
	
	    #if 1 /*======== Start Hardcode idx2: report_mobility_ind ========*/
	    {
		    	if (p_e2sm_rrc_ric_indication->bitmask & IND_RIC_MOBILITY_REPORT)
		    	{
			    		#if 1 /*======== Start Hardcode idx3: ho_attempt ========*/
			    	{
				    		p_e2sm_rrc_ric_indication.report_mobility_ind.ho_attempt = 0; /* change integer here */
			    	}
			    	#endif /*======== End Hardcode idx3: ho_attempt ========*/
			
			    	#if 1 /*======== Start Hardcode idx4: ho_succ ========*/
			    	{
				    		p_e2sm_rrc_ric_indication.report_mobility_ind.ho_succ = 0; /* change integer here */
			    	}
			    	#endif /*======== End Hardcode idx4: ho_succ ========*/
			
			    	#if 1 /*======== Start Hardcode idx5: ho_failure ========*/
			    	{
				    		p_e2sm_rrc_ric_indication.report_mobility_ind.ho_failure = 0; /* change integer here */
			    	}
			    	#endif /*======== End Hardcode idx5: ho_failure ========*/
		    	}
	    }
	    #endif /*======== End Hardcode idx2: report_mobility_ind ========*/
	
	    return XNAP_SUCCESS;
}
