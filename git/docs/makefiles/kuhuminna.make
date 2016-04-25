; Core
; --------
core = 7.x

api = 2
projects[drupal][version] = "7.x"
projects[drupal][type] = core
;projects[drupal][patch][] = 'https://www.drupal.org/files/openid_verbose_logging-1078476-13.patch'
;projects[drupal][patch][] = 'sites/all/modules/custom/kultuurikava/patches/openid_patch-for-openid-ee.patch'
projects[drupal][patch][] = 'sites/all/modules/custom/kultuurikava/patches/openid-mobileid-login.patch'

; Contrib modules
; --------

projects[google_analytics][subdir] = "contrib"
projects[google_analytics][version] = "2.1"
projects[google_analytics][type] = "module"

projects[autosave][subdir] = "contrib"
projects[autosave][version] = "2.2"
projects[autosave][type] = "module"

projects[better_exposed_filters][subdir] = "contrib"
projects[better_exposed_filters][version] = "3.0"
projects[better_exposed_filters][type] = "module"

projects[block_class][subdir] = "contrib"
projects[block_class][version] = "2.1"
projects[block_class][type] = "module"

projects[cache_control][subdir] = "contrib"
projects[cache_control][version] = "2.0-rc1"
projects[cache_control][type] = "module"

projects[colorbox][subdir] = "contrib"
projects[colorbox][version] = "2.10"
projects[colorbox][type] = "module"

projects[computed_field][subdir] = "contrib"
projects[computed_field][version] = "1.0"
projects[computed_field][type] = "module"

projects[context][subdir] = "contrib"
projects[context][version] = "3.6"
projects[context][type] = "module"

projects[ctools][subdir] = "contrib"
projects[ctools][version] = "1.9"
projects[ctools][type] = "module"

projects[date][subdir] = "contrib"
projects[date][version] = "2.8"
projects[date][type] = "module"
projects[date][patch][] = "https://www.drupal.org/files/issues/date-expoded_grouped_filters-1876168-61.patch"

projects[datepicker][subdir] = "contrib"
projects[datepicker][version] = "1.0"
projects[datepicker][type] = "module"

projects[delete_all][subdir] = "contrib"
projects[delete_all][version] = "1.1"
projects[delete_all][type] = "module"

projects[devel][subdir] = "contrib"
projects[devel][version] = "1.5"
projects[devel][type] = "module"

projects[elysia_cron][subdir] = "contrib"
projects[elysia_cron][version] = "2.x-dev"
projects[elysia_cron][type] = "module"

projects[entity][subdir] = "contrib"
projects[entity][version] = "1.6"
projects[entity][type] = "module"

projects[entity_view_mode][subdir] = "contrib"
projects[entity_view_mode][version] = "1.0-rc1"
projects[entity_view_mode][type] = "module"

projects[facetapi][subdir] = "contrib"
projects[facetapi][version] = "1.5"
projects[facetapi][type] = "module"

projects[features][subdir] = "contrib"
projects[features][version] = "2.7"
projects[features][type] = "module"

projects[field_collection][subdir] = "contrib"
projects[field_collection][version] = "1.0-beta10"
projects[field_collection][type] = "module"
;projects[field_collection][patch][] = 'https://www.drupal.org/files/issues/2384323-16-dont-try-to-delete-missing-items.patch'
;projects[field_collection][patch][] = 'https://www.drupal.org/files/issues/field_collection-check-before-adding-index-2141781-27.patch'
;projects[field_collection][patch][] = 'https://www.drupal.org/files/issues/field_collection-item_delete_check_load_result-2436721-1.patch'
projects[field_collection][patch][] = 'https://www.drupal.org/files/issues/field-collection-2599248-2.patch'

projects[field_permissions][subdir] = "contrib"
projects[field_permissions][version] = "1.0-beta2"
projects[field_permissions][type] = "module"

projects[geolocation][subdir] = "contrib"
projects[geolocation][version] = "1.6"
projects[geolocation][type] = "module"
projects[geolocation][patch][] = 'sites/all/modules/custom/kultuurikava/patches/geolocation_googlemaps-kuhuminna-error-reporting.patch'

projects[i18n][subdir] = "contrib"
projects[i18n][version] = "1.12"
projects[i18n][type] = "module"

projects[i18nviews][subdir] = "contrib"
projects[i18nviews][version] = "3.x-dev"
projects[i18nviews][type] = "module"

projects[ife][subdir] = "contrib"
projects[ife][version] = "2.0-alpha2"
projects[ife][type] = "module"
projects[ife][patch][] = "https://www.drupal.org/files/issues/ife-notice-2123685-2.patch"

projects[imce][subdir] = "contrib"
projects[imce][version] = "1.9"
projects[imce][type] = "module"

projects[imce_wysiwyg][subdir] = "contrib"
projects[imce_wysiwyg][version] = "1.0"
projects[imce_wysiwyg][type] = "module"

projects[jquery_update][subdir] = "contrib"
projects[jquery_update][version] = "3.0-alpha2"
projects[jquery_update][type] = "module"

projects[l10n_update][subdir] = "contrib"
projects[l10n_update][version] = "1.1"
projects[l10n_update][type] = "module"

projects[libraries][subdir] = "contrib"
projects[libraries][version] = "2.2"
projects[libraries][type] = "module"

projects[link][subdir] = "contrib"
projects[link][version] = "1.3"
projects[link][type] = "module"

projects[link_click_count][subdir] = "contrib"
projects[link_click_count][version] = "2.2"
projects[link_click_count][type] = "module"
;projects[link_click_count][patch][] = 'sites/all/modules/custom/kultuurikava/patches/link_click_count-clicking-patch.patch'

projects[login_destination][subdir] = "contrib"
projects[login_destination][version] = "1.1"
projects[login_destination][type] = "module"

projects[loft_data_grids][subdir] = "contrib"
projects[loft_data_grids][version] = "2.1-rc9"
projects[loft_data_grids][type] = "module"

projects[mailcontrol][subdir] = "contrib"
projects[mailcontrol][version] = "1.0"
projects[mailcontrol][type] = "module"

projects[menu_item_visibility][subdir] = "contrib"
projects[menu_item_visibility][version] = "1.0-beta1"
projects[menu_item_visibility][type] = "module"

projects[menu_token][subdir] = "contrib"
projects[menu_token][version] = "1.0-beta5"
projects[menu_token][type] = "module"

projects[metatag][subdir] = "contrib"
projects[metatag][version] = "1.7"
projects[metatag][type] = "module"

projects[modal_forms][subdir] = "contrib"
projects[modal_forms][version] = "1.x-dev"
projects[modal_forms][type] = "module"

projects[module_filter][subdir] = "contrib"
projects[module_filter][version] = "2.0"
projects[module_filter][type] = "module"

projects[multiupload_filefield_widget][subdir] = "contrib"
projects[multiupload_filefield_widget][version] = "1.13"
projects[multiupload_filefield_widget][type] = "module"

projects[multiupload_imagefield_widget][subdir] = "contrib"
projects[multiupload_imagefield_widget][version] = "1.3"
projects[multiupload_imagefield_widget][type] = "module"

projects[nocurrent_pass][subdir] = "contrib"
projects[nocurrent_pass][version] = "1.0"
projects[nocurrent_pass][type] = "module"

projects[node_edit_protection][subdir] = "contrib"
projects[node_edit_protection][version] = "1.1"
projects[node_edit_protection][type] = "module"

projects[nodeaccess_userreference][subdir] = "contrib"
projects[nodeaccess_userreference][version] = "3.10"
projects[nodeaccess_userreference][type] = "module"

projects[nodequeue][subdir] = "contrib"
projects[nodequeue][version] = "2.0"
projects[nodequeue][type] = "module"

projects[openid_ee][subdir] = "contrib"
projects[openid_ee][version] = "1.x-dev"
projects[openid_ee][type] = "module"
projects[openid_ee][patch][] = 'sites/all/modules/custom/kultuurikava/patches/openid_ee_url-port-removal.patch'

projects[pasteformat][subdir] = "contrib"
projects[pasteformat][version] = "1.5"
projects[pasteformat][type] = "module"

projects[pathauto][subdir] = "contrib"
projects[pathauto][version] = "1.3"
projects[pathauto][type] = "module"

projects[references][subdir] = "contrib"
projects[references][version] = "2.1"
projects[references][type] = "module"

projects[quicktabs][subdir] = "contrib"
projects[quicktabs][version] = "3.6"
projects[quicktabs][type] = "module"

projects[scheduler][subdir] = "contrib"
projects[scheduler][version] = "1.3"
projects[scheduler][type] = "module"

projects[search_api][subdir] = "contrib"
projects[search_api][version] = "1.16"
projects[search_api][type] = "module"

projects[strongarm][subdir] = "contrib"
projects[strongarm][version] = "2.0"
projects[strongarm][type] = "module"

projects[token][subdir] = "contrib"
projects[token][version] = "1.6"
projects[token][type] = "module"

projects[transliteration][subdir] = "contrib"
projects[transliteration][version] = "3.2"
projects[transliteration][type] = "module"

projects[users_export][subdir] = "contrib"
projects[users_export][version] = "2.0-rc7"
projects[users_export][type] = "module"

projects[variable][subdir] = "contrib"
projects[variable][version] = "2.5"
projects[variable][type] = "module"

projects[video_embed_field][subdir] = "contrib"
projects[video_embed_field][version] = "2.0-beta11"
projects[video_embed_field][type] = "module"

projects[views][subdir] = "contrib"
projects[views][version] = "3.11"
projects[views][type] = "module"

projects[views_bulk_operations][subdir] = "contrib"
projects[views_bulk_operations][version] = "3.3"
projects[views_bulk_operations][type] = "module"

projects[views_distinct][subdir] = "contrib"
projects[views_distinct][version] = "1.0"
projects[views_distinct][type] = "module"

projects[views_node_access_level][subdir] = "contrib"
projects[views_node_access_level][version] = "1.0"
projects[views_node_access_level][type] = "module"

projects[views_php][subdir] = "contrib"
projects[views_php][version] = "1.0-alpha3"
projects[views_php][type] = "module"

projects[webform][subdir] = "contrib"
projects[webform][version] = "4.12"
projects[webform][type] = "module"

projects[wysiwyg][subdir] = "contrib"
projects[wysiwyg][version] = "2.x-dev"
projects[wysiwyg][type] = "module"

projects[touch_icons][subdir] = "contrib"
projects[touch_icons][version] = "1.x-dev"
projects[touch_icons][type] = "module"


; Themes
; ---------
projects[omega][version] = "4.3"
projects[omega][type] = "theme"
projects[omega][patch][] = 'https://www.drupal.org/files/issues/2026149_42.patch'
projects[omega][patch][] = 'https://www.drupal.org/files/issues/omega-fix-direction-language-rtl-2364731-7.patch'

; Libraries
; ---------
libraries[ckeditor][download][type] = "file"
libraries[ckeditor][download][url] = "http://download.cksource.com/CKEditor/CKEditor/CKEditor%204.5.5/ckeditor_4.5.5_standard.zip"
libraries[ckeditor][directory_name] = "ckeditor"
libraries[ckeditor][type] = "library"
