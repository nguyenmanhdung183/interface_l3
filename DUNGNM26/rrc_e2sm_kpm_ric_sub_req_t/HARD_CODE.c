
xnap_return_et assign_hardcode_value_rrc_e2sm_kpm_ric_sub_req_t( rrc_e2sm_kpm_ric_sub_req_t *p_rrc_e2sm_kpm_ric_sub_req )
{
	    #if 1 /*======== Start Hardcode idx0: bitmask ========*/
	    {
		    	p_rrc_e2sm_kpm_ric_sub_req.bitmask = 0; /* change integer here */
	    }
	    #endif /*======== End Hardcode idx0: bitmask ========*/
	
	    #if 1 /*======== Start Hardcode idx1: ric_request_id ========*/
	    {
		    	p_rrc_e2sm_kpm_ric_sub_req.ric_request_id = 0; /* change integer here */
	    }
	    #endif /*======== End Hardcode idx1: ric_request_id ========*/
	
	    #if 1 /*======== Start Hardcode idx2: periodic ========*/
	    {
		    	p_rrc_e2sm_kpm_ric_sub_req.periodic = 0; /* change integer here */
	    }
	    #endif /*======== End Hardcode idx2: periodic ========*/
	
	    #if 1 /*======== Start Hardcode idx3: report_period_ms ========*/
	    {
		    	p_rrc_e2sm_kpm_ric_sub_req.report_period_ms = 0; /* change integer here */
	    }
	    #endif /*======== End Hardcode idx3: report_period_ms ========*/
	
	    #if 1 /*======== Start Hardcode idx4: report_mobility_req ========*/
	    {
		    	if (p_rrc_e2sm_kpm_ric_sub_req->bitmask & SUB_RIC_MOBILITY_REPORT)
		    	{
			    		#if 1 /*======== Start Hardcode idx5: is_ho_attempt ========*/
			    	{
				    		p_rrc_e2sm_kpm_ric_sub_req.report_mobility_req.is_ho_attempt = 0; /* change integer here */
			    	}
			    	#endif /*======== End Hardcode idx5: is_ho_attempt ========*/
			
			    	#if 1 /*======== Start Hardcode idx6: is_ho_succ ========*/
			    	{
				    		p_rrc_e2sm_kpm_ric_sub_req.report_mobility_req.is_ho_succ = 0; /* change integer here */
			    	}
			    	#endif /*======== End Hardcode idx6: is_ho_succ ========*/
			
			    	#if 1 /*======== Start Hardcode idx7: is_ho_failure ========*/
			    	{
				    		p_rrc_e2sm_kpm_ric_sub_req.report_mobility_req.is_ho_failure = 0; /* change integer here */
			    	}
			    	#endif /*======== End Hardcode idx7: is_ho_failure ========*/
		    	}
	    }
	    #endif /*======== End Hardcode idx4: report_mobility_req ========*/
	
	    return XNAP_SUCCESS;
}
