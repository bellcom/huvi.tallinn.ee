<?php
if (!isset($row->field_data_field_schedule_date_field_schedule_date_value)) {
  print t('Katusüritus');
}
else if (date("H:i", $row->field_data_field_schedule_date_field_schedule_date_value) == "23:55"){
  print '<span class="date-display-single">';
  print t('Kogu päev');
  print '<span>';
}
else
  print $output;
