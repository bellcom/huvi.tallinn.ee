<?php
// Run example: drush --uri=https://huvi.tallinn.ee.dd:8443 scr get_user_content_sql.php {{int_uid}}

if($_SERVER['HTTP_USER_AGENT']){
    die();
}
print('Starting..' . PHP_EOL);
/** bootstrap Drupal * */
chdir(__DIR__);
require_once './includes/bootstrap.inc';
drupal_bootstrap(DRUPAL_BOOTSTRAP_FULL);
print('Drupal bootstrap done..' . PHP_EOL);
$user_id = $_SERVER['argv'][6];
print('Loading data for user: ' . $user_id . PHP_EOL);

$query = db_query('SELECT n.nid
FROM {node} n WHERE n.uid = :uid', array(':uid' => $user_id));
$result = $query->fetchAll();
foreach ($result as $record) {
print_r("UPDATE node SET node.uid = ? WHERE node.nid = $record->nid;" . PHP_EOL);
}
print_r(PHP_EOL);
$query = db_query('SELECT n.nid
FROM {node_revision} n WHERE n.uid = :uid', array(':uid' => $user_id));
$result = $query->fetchAll();
foreach ($result as $record) {
print_r("UPDATE node_revision SET node_revision.uid = ? WHERE node.nid = $record->nid;" . PHP_EOL);
}
print_r(PHP_EOL);
$query = db_query('SELECT n.aid
FROM {authmap} n WHERE n.uid = :uid', array(':uid' => $user_id));
$result = $query->fetchAll();
foreach ($result as $record) {
print_r("UPDATE authmap SET authmap.uid = ? WHERE authmap.aid = $record->aid;" . PHP_EOL);
}
print_r(PHP_EOL);
$query = db_query('SELECT n.fid
FROM {file_managed} n WHERE n.uid = :uid', array(':uid' => $user_id));
$result = $query->fetchAll();
foreach ($result as $record) {
print_r("UPDATE file_managed SET file_managed.uid = ? WHERE file_managed.aid = $record->fid;" . PHP_EOL);
}
print_r(PHP_EOL);

print('Finish.' . PHP_EOL);