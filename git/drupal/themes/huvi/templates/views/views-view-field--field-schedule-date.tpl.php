<?php

if (date("H:i", $row->field_data_field_schedule_date_field_schedule_date_value) == "23:55"){
  print '<span class="date-display-single">';
  print t('Terve päev');
  print '<span>';
} 
else
  print $output;
