Steps to install kuhuminna local environment
======
1. ssh into staging/production, “cd /var/www/”
2. tar gzip the /html directory, "tar -pcvzf kuhuminna.tar.gz html"
3. download it to your local machine "scp root@kuhuminna.dmz.exove.net:/var/www/kuhuminna.tar.gz ."
4. extract it "tar -pxvzf kuhuminna.tar.gz"
5. dump and import the staging/production database to your local mysql server
6. update "/sites/default/settings.php" with the new DB details
7. clone git: "git clone git@git.exove.net:clients/kuhuminna"
8. Create symlinks:
  [path_to_git]/drupal/modules/custom -> [drupal_root]/sites/all/modules/custom
  [path_to_git]/drupal/themes/kuhuminna -> [drupal_root]/sites/all/themes/kuhuminna
  [path_to_git]/docs/makefiles/kuhuminna.make -> [drupal_root]/kuhuminna.make

9. Run make file in drupal root folder to download missing modules (if some) "drush make kuhuminna.make"


Front-end Notes
======
- Omega 4.x and SASS are used
- Make sure you are running Ruby 1.9.3 (or newer)
- Install bundler and then run it against the Gemfile
  gem install bundler
  bundle install
  (must be executed from the subtheme's directory in order to pick up the list of dependencies)

- Use "bundle exec compass watch" when working with SASS
(Note that using "compass watch" without "bundle exec" might not work correctly on all environments)

Detailed information about Omega 4 requirements: https://www.drupal.org/node/2172619