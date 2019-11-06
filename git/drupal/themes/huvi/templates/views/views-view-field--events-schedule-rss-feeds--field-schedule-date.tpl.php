<?php

if (date("H:i", $row->field_data_field_schedule_date_field_schedule_date_value) == "23:55"){
  print date("d-m-Y", $row->field_data_field_schedule_date_field_schedule_date_value) . ' - ' .  t('Kogu päev');
}
else
  print $output;
