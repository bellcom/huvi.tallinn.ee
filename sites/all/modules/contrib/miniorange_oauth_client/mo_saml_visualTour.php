<?php

drupal_add_css( drupal_get_path('module', 'miniorange_oauth_client'). '/css/bootstrap.min.css' , array('group' => CSS_DEFAULT, 'every_page' => FALSE));
drupal_add_css( drupal_get_path('module', 'miniorange_oauth_client'). '/css/mo-card.css' , array('group' => CSS_DEFAULT, 'every_page' => FALSE));
drupal_add_js(drupal_get_path('module', 'miniorange_oauth_client') . '/js/dru_visual_tour.js');

$Tour_taken = variable_get('mo_saml_tourTaken_' . getPage_name(), false);

drupal_add_js(array('moTour' => array(
    'pageID' => getPage_name(),
    'tourData' => getTourData(getPage_name(),$Tour_taken),
    'tourTaken' => $Tour_taken,
    'addID' => addID(),
    'pageURL' => $_SERVER['REQUEST_SCHEME'] . "://" . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'],

)), array('type' => 'setting'));
variable_set('mo_saml_tourTaken_' . getPage_name(), true);
//variable_set('mo_saml_tourTaken_'.$_POST['pageID'], $_POST['doneTour']);

if(isset($_POST['doneTour']) && isset($_POST['pageID']))
{
    variable_set('mo_saml_tourTaken_'.$_POST['pageID'], $_POST['doneTour']);
}

function getPage_name()
{
    $link = (isset($_SERVER['HTTPS']) && $_SERVER['HTTPS'] === 'on' ? "https" : "http") . "://" . $_SERVER['HTTP_HOST'] . $_SERVER['REQUEST_URI'];
    $exploded = explode('/', $link);
    $l_url = end($exploded);
    $l_url = multiexplode(array("?","%","#",":","="),$l_url);
    $f_url = $l_url[0];
    return $f_url;
}

function multiexplode ($delimiters,$string)
{
    $ready = str_replace($delimiters, $delimiters[0], $string);
    $launch = explode($delimiters[0], $ready);
    return  $launch;
}

function mo_visual_tour()
{
    $firstTour = true;
    echo '<div id="restart_tour_button" class="mo-otp-help-button static" style="margin-right:10px;z-index:10">
    <button class="button button-primary button-large">
    <span class="dashicons dashicons-controls-repeat" style="margin:5% 0 0 0;"></span>
        '.mo_("Restart Tour").'
    </button>
    </div>';
}

function addID()
{
    $idArray = array(
        array(
            'selector'  =>'.tabs li:nth-of-type(1)>a',
            'newID'     =>'mo_vt_congig_oauth',
        ),
        array(
            'selector'  =>'.tabs li:nth-of-type(2)>a',
            'newID'     =>'mo_vt_mapping',
        ),
        array(
            'selector'  =>'.tabs li:nth-of-type(3)>a',
            'newID'     =>'mo_vt_signin',
        ),
        array(
            'selector'  =>'.tabs li:nth-of-type(4)>a',
            'newID'     =>'mo_vt_reports',
        ),
        array(
            'selector'  =>'.tabs li:nth-of-type(5)>a',
            'newID'     =>'mo_vt_licensing_plans',
        ),
        array(
            'selector'  =>'.tabs li:nth-of-type(6)>a',
            'newID'     =>'mo_vt_support',
        ),
        array(
            'selector'  =>'.tabs li:nth-of-type(7)>a',
            'newID'     =>'mo_vt_account',
        ),

    );
    return $idArray;
}


function getTourData($pageID,$Tour_Taken)
{
    $tourData = array();
    global $base_url;
    $module_path = drupal_get_path('module', 'miniorange_oauth_client');
    $root = $base_url.'/'.$module_path;
    $img = $root."/includes/images/startTour.png";
    $img1 = $root."/includes/images/choose.svg";
    $img2 = $root."/includes/images/mapping.svg";
    $img3 = $root."/includes/images/settings.jpg";
    $img4 = $root."/includes/images/upgrade1.png";
    $img5 = $root."/includes/images/callback.png";
    $img6 = $root."/includes/images/connection.png";
    $img7 = $root."/includes/images/green_check.png";
    $img8 = $root."/includes/images/save.png";
    $img9 = $root."/includes/images/documentation.png";
    $img10 = $root."/includes/images/need_help.png";

    if($Tour_Taken == FALSE)
        $tab_index = 'miniorange_oauth_client';
    else $tab_index = 'mo_oauth';

    if($Tour_Taken == FALSE) {
        $tourData['miniorange_oauth_client'] = array(
            0 => array(
                'targetE'       => '',
                'pointToSide'   => 'center',
                'titleHTML'     => '<h1>Welcome!</h1>',
                'contentHTML'   => 'Fasten your seat belts for a quick ride.',
                'ifNext'        => true,
                'buttonText'    => 'Let\'s go',
                'img'           => $img,
                'cardSize'      => 'big',
            ),
            1 => array(
                'targetE'       => 'mo_vt_congig_oauth',
                'pointToSide'   => 'up',
                'titleHTML'     => '<h1>Configure OAuth</h1>',
                'contentHTML'   => 'Configure your OAuth Server with OAuth Client here to perform SSO.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           => $img1,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            2 => array(
                'targetE'       => 'mo_vt_mapping',
                'pointToSide'   => 'up',
                'titleHTML'     => '<h1>Attribute Mapping</h1>',
                'contentHTML'   => 'In this tab, you can perform Attribute and Role Mapping configurations.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           => $img2,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            3 => array(
                'targetE'       => 'mo_vt_signin',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Signin Settings</h1>',
                'contentHTML'   => 'Here you can select between various sign in options.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           => $img3,
                'cardSize'      => 'big',
            ),
            4 => array(
                'targetE'       => 'mo_vt_licensing_plans',
                'pointToSide'   => 'up',
                'titleHTML'     => '<h1>Upgrade here</h1>',
                'contentHTML'   => 'You can see the complete list of features that we provide in our various plans and can also upgrade to any of them.',
                'ifNext'        => true,
                'buttonText'    => 'End Tour',
                'img'           => $img4,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            5 => array(
                'targetE'       => 'mo_configure_selectapp_vt',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Select Application</h1>',
                'contentHTML'   => 'Please select your OAuth server to configure. Select Custom OAuth if your server not listed.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           =>  $img1,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            6 => array(
                'targetE'       => 'mo_oauth_callback_vt',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Callback/Redirect URL</h1>',
                'contentHTML'   => 'Provide this <b>Callback/Redirect URL</b> to your OAuth Server to configure your OAuth Client.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           =>  $img5,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            7 => array(
                'targetE'       => 'mo_select_app_config_vt',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Confiugre OAuth Server</h1>',
                'contentHTML'   => 'Enter details to configure your OAuth Server.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           =>  $img1,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            8 => array(
                'targetE'       => 'mo_vt_add_data2',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Scope</h1>',
                'contentHTML'   => 'Scope decides the range of data that comes from your OAuth Server.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           => $img1,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            9 => array(
                'targetE'       => 'mo_vt_add_data5',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Endpoints</h1>',
                'contentHTML'   => 'The endpoints from your OAuth Server will be used during OAuth SSO login.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           => $img6,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            10 => array(
                'targetE'       => 'mo_vt_add_data4',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Enable login with OAuth</h1>',
                'contentHTML'   => 'Enable the switch if you want to enable SSO login with OAuth.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           => $img7,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            11 => array(
                'targetE'       => 'button_config',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Save Settings</h1>',
                'contentHTML'   => 'You can save your configurations by clicking on this button.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           => $img8,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            12 => array(
                'targetE'       => 'mo_oauth_guide_vt',
                'pointToSide'   => 'right',
                'titleHTML'     => '<h1>Documentaion</h1>',
                'contentHTML'   => 'To see step by step guides of how to configure Drupal OAuth Client with any OAuth Server.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           => $img9,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            13 =>    array(
                'targetE'       =>  'mosaml-feedback-form',
                'pointToSide'   =>  'right',
                'titleHTML'     =>  '<h1>Need Help?</h1>',
                'contentHTML'   =>  'You can always reach out to us instantly in case you face any issues or have any questions in mind.',
                'ifNext'        =>  true,
                'buttonText'    =>  'End Tour',
                'img'           =>  $img10,
                'cardSize'      =>  'big',
                'action'        =>  '',
                'ifskip'        =>  'hidden',
            ),
        );
    }else {
        $tourData['miniorange_oauth_client'] = array(
            0 => array(
                'targetE'       => 'mo_configure_selectapp_vt',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Select Application</h1>',
                'contentHTML'   => 'Please select your OAuth server to configure. Select Custom OAuth if your server not listed.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           =>  $img1,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            1 => array(
                'targetE'       => 'mo_oauth_callback_vt',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Callback/Redirect URL</h1>',
                'contentHTML'   => 'Provide this <b>Callback/Redirect URL</b> to your OAuth Server to configure your OAuth Client.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           => array(),
                'img'           =>  $img5,
                'cardSize'      => 'big',
            ),
            2 => array(
                'targetE'       => 'mo_select_app_config_vt',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Confiugre OAuth Server</h1>',
                'contentHTML'   => 'Enter details to configure your OAuth Server.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           =>  $img1,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            3 => array(
                'targetE'       => 'mo_vt_add_data2',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Scope</h1>',
                'contentHTML'   => 'Scope decides the range of data that comes from your OAuth Server.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           => $img1,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            4 => array(
                'targetE'       => 'mo_vt_add_data5',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Endpoints</h1>',
                'contentHTML'   => 'The endpoints from your OAuth Server will be used during OAuth SSO login.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           => $img6,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            5 => array(
                'targetE'       => 'mo_vt_add_data4',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Enable login with OAuth</h1>',
                'contentHTML'   => 'Enable the switch if you want to enable SSO login with OAuth.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           =>  $img7,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            6 => array(
                'targetE'       => 'button_config',
                'pointToSide'   => 'left',
                'titleHTML'     => '<h1>Save Settings</h1>',
                'contentHTML'   => 'You can save your configurations by clicking on this button.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           =>  $img8,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            7 => array(
                'targetE'       => 'mo_oauth_guide_vt',
                'pointToSide'   => 'right',
                'titleHTML'     => '<h1>Documentaion</h1>',
                'contentHTML'   => 'To see step by step guides of how to configure Drupal OAuth Client with any OAuth Server.',
                'ifNext'        => true,
                'buttonText'    => 'Next',
                'img'           =>  $img9,
                'cardSize'      => 'big',
                'action'        => '',
            ),
            8 =>    array(
                'targetE'       =>  'mosaml-feedback-form',
                'pointToSide'   =>  'right',
                'titleHTML'     =>  '<h1>Need Help?</h1>',
                'contentHTML'   =>  'You can always reach out to us instantly in case you face any issues or have any questions in mind.',
                'ifNext'        =>  true,
                'buttonText'    =>  'End Tour',
                'img'           =>  $img10,
                'cardSize'      =>  'big',
                'action'        =>  '',
                'ifskip'        =>  'hidden',
            ),
        );
    }
    $tourData['attr_mapping'] = array(
        0 =>    array(
            'targetE'       =>  'mo_oauth_vt_attrn',
            'pointToSide'   =>  'left',
            'titleHTML'     =>  '<h1>Email Attribute</h1>',
            'contentHTML'   =>  'Please enter attribute name which holds email address here. You can find this in test configuration',
            'ifNext'        =>  true,
            'buttonText'    =>  'Next',
            'img'           =>  $img1,
            'cardSize'      =>  'big',
            'action'        =>  '',
        ),
        1 =>    array(
            'targetE'       =>  'mo_oauth_vt_attre',
            'pointToSide'   =>  'left',
            'titleHTML'     =>  '<h1>Name Attribute</h1>',
            'contentHTML'   =>  'Enter the Username Attribute which holds name. You can find this in test configuration.',
            'ifNext'        =>  true,
            'buttonText'    =>  'Next',
            'img'           =>  $img1,
            'cardSize'      =>  'big',
            'action'        =>  '',
        ),
        2 =>    array(
            'targetE'       =>  'mosaml-feedback-form',
            'pointToSide'   =>  'right',
            'titleHTML'     =>  '<h1>Need Help?</h1>',
            'contentHTML'   =>  'You can always reach out to us instantly in case you face any issues or have any questions in mind.',
            'ifNext'        =>  true,
            'buttonText'    =>  'End Tour',
            'img'           =>  $img10,
            'cardSize'      =>  'big',
            'action'        =>  '',
            'ifskip'        =>  'hidden',
        ),
    );
    $tourData['licensing'] = array(
        0 =>    array(
            'targetE'       =>  'mosaml-feedback-form',
            'pointToSide'   =>  'right',
            'titleHTML'     =>  '<h1>Want a demo?</h1>',
            'contentHTML'   =>  'Want to test any paid modules before purchasing? Just send us a request.',
            'ifNext'        =>  true,
            'buttonText'    =>  'End Tour',
            'img'           =>  $img10,
            'cardSize'      =>  'big',
            'action'        =>  '',
            'ifskip'        =>  'hidden',
        ),
    );
    return isset($tourData[$pageID]) ? $tourData[$pageID] : '';
}

/*
                            ********************************
                                    array terms :
                            ********************************
pageID              -   your Page ID, contains array of popups
0                   -   Popup/card number, goes from zero to n. For next Tab card use 'nextCard' instead of number
targetE             -   Element to target to. Has to be element ID without #. If no ID, add one. Empty For none, shows in centre of screen if empty
pointToSide         -   Direction of arrow to point to (up,down,left,right), for no arrow-keep empty (places at center keep targetE empty) //look at this fix
titleHTML           -   Title of card, can be HTML code
contentHTML         -   Content of card, can be HTML code
ifNext              -   if to show(true) Next Button or not(false), Keep False for Card Number('nextTab')
buttonText          -   Next Button Text
img                 -   image(icon) attributes ('src' should not be 'empty' with 'visible' true)
                        src     -   url of image(best for ico/transparent png) icon(https://visualpharm.com/assets/262/Comments-595b40b65ba036ed117d3e48.svg)
                        visible -   to show image or not, true or false
cardSize            -   Card has 3 difined sizes- big, medium and small. Recomended not to use image with small
nextTab             -   This is special card used if you want user to move to next tab during tour, disabled during restart tour

 */