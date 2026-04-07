static
gnb_length_t
gnb_il_get_rrc_mnc_len 
(
    rrc_mnc_t * p_rrc_mnc;
);


static
gnb_return_et
gnb_il_compose_rrc_mnc 
(
    UInt8 **pp_buffer,
    rrc_mnc_t * p_rrc_mnc
);


static
gnb_length_t
gnb_il_get_rrc_plmn_identity_len 
(
    rrc_plmn_identity_t * p_rrc_plmn_identity;
);


static
gnb_return_et
gnb_il_compose_rrc_plmn_identity 
(
    UInt8 **pp_buffer,
    rrc_plmn_identity_t * p_rrc_plmn_identity
);


static
gnb_length_t
gnb_il_get_rrc_nr_cell_identity_len 
(
    rrc_nr_cell_identity_t * p_rrc_nr_cell_identity;
);


static
gnb_return_et
gnb_il_compose_rrc_nr_cell_identity 
(
    UInt8 **pp_buffer,
    rrc_nr_cell_identity_t * p_rrc_nr_cell_identity
);


static
gnb_length_t
gnb_il_get_rrc_ncgi_len 
(
    rrc_ncgi_t * p_rrc_ncgi;
);


static
gnb_return_et
gnb_il_compose_rrc_ncgi 
(
    UInt8 **pp_buffer,
    rrc_ncgi_t * p_rrc_ncgi
);


static
gnb_length_t
gnb_il_get_e2_report_mobility_req_len 
(
    e2_report_mobility_req_t * p_e2_report_mobility_req;
);


static
gnb_return_et
gnb_il_compose_e2_report_mobility_req 
(
    UInt8 **pp_buffer,
    e2_report_mobility_req_t * p_e2_report_mobility_req
);


static
gnb_length_t
gnb_il_get_e2ap_ric_action_list_len 
(
    e2ap_ric_action_list_t * p_e2ap_ric_action_list;
);


static
gnb_return_et
gnb_il_compose_e2ap_ric_action_list 
(
    UInt8 **pp_buffer,
    e2ap_ric_action_list_t * p_e2ap_ric_action_list
);


static
gnb_length_t
gnb_il_get_rrc_e2sm_kpm_ric_sub_req_len 
(
    rrc_e2sm_kpm_ric_sub_req_t * p_rrc_e2sm_kpm_ric_sub_req;
);


static
gnb_return_et
gnb_il_compose_rrc_e2sm_kpm_ric_sub_req 
(
    UInt8 **pp_buffer,
    rrc_e2sm_kpm_ric_sub_req_t * p_rrc_e2sm_kpm_ric_sub_req
);


