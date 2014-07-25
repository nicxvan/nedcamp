<?php

/**
 * @file
 * Default simple view template to all the fields as a row.
 *
 * - $view: The view in use.
 * - $fields: an array of $field objects. Each one contains:
 *   - $field->content: The output of the field.
 *   - $field->raw: The raw data for the field, if it exists. This is NOT output safe.
 *   - $field->class: The safe class id to use.
 *   - $field->handler: The Views field handler object controlling this field. Do not use
 *     var_export to dump this object, as it can't handle the recursion.
 *   - $field->inline: Whether or not the field should be inline.
 *   - $field->inline_html: either div or span based on the above flag.
 *   - $field->wrapper_prefix: A complete wrapper containing the inline_html to use.
 *   - $field->wrapper_suffix: The closing tag for the wrapper.
 *   - $field->separator: an optional separator that may appear before a field.
 *   - $field->label: The wrap label text to use.
 *   - $field->label_html: The full HTML of the label to use including
 *     configured element type.
 * - $row: The raw result object from the query, with all data it fetched.
 *
 * @ingroup views_templates
 
  <?php foreach ($fields as $id => $field): ?>
    <?php if (!empty($field->separator)): ?>
      <?php print $field->separator; ?>
    <?php endif; ?>

    <?php print $field->wrapper_prefix; ?>
      <?php print $field->label_html; ?>
      <?php print $field->content; ?>
    <?php print $field->wrapper_suffix; ?>
  <?php endforeach; ?>
 
 */


	//:::::::::::::::::::::::::::::::::::
	//:: Variable Definitions
	//:::::::::::::::::::::::::::::::::::
	$editLink = $fields["edit_node"]->content;
	$bannerTemplate = $row->field_field_banner_style_node["0"]["raw"]["taxonomy_term"]->description;
	$bannerStyle = $row->field_field_banner_style_node["0"]["rendered"]["#markup"];
	$title = $row->field_field_banner_display_title["0"]["rendered"]["#markup"];
	$imageStyle = $row->field_field_image_style["0"]["rendered"]["#title"];
	$description = $row->field_body["0"]["rendered"]["#markup"];
	$pageAssociation = $row->field_field_page_association["0"]["rendered"]["#markup"];
	$pageURL = $row->field_field_page_url["0"]["rendered"]["#markup"];
	$buttonLabel = $row->field_field_button_label["0"]["rendered"]["#markup"];
	$publicFilePath = variable_get('file_public_path', conf_path() . '/files');
	$privateFilePath = variable_get('file_private_path');
  $newWindow = '';

  
  if (strlen($pageAssociation) == 0) {
    $pageAssociation = $pageURL;
    $newWindow = 'rel="external"';
  }

  
	//:: Images: $bannerImage 
  if (strlen($imageStyle) == 0) {
    $bannerImageUrl = $row->field_field_banner_link_image["0"]["rendered"]["#item"]["uri"];
    $bannerImageUrl = str_replace('public:/', $publicFilePath, $bannerImageUrl);
  }
	else {
    $bannerImageUrl = image_style_url($imageStyle, $row->field_field_banner_link_image["0"]["rendered"]["#item"]["uri"]);
  }
  
	$bannerImageAlt = $row->field_field_banner_link_image["0"]["rendered"]["#item"]["alt"];
	$bannerImageTitle = $row->field_field_banner_link_image["0"]["rendered"]["#item"]["title"];
	$bannerImageHeight = "";
	$bannerImageWidth = "";

  
	//:::::::::::::::::::::::::::::::::::
	//:: Rewrite/Replace Markup
	//:::::::::::::::::::::::::::::::::::
	$bannerMarkup = str_replace('$bannerStyle',$bannerStyle,$bannerTemplate);
	$bannerMarkup = str_replace('$title',$title,$bannerMarkup);
	$bannerMarkup = str_replace('$description',$description,$bannerMarkup);
	$bannerMarkup = str_replace('$pageAssociation',$pageAssociation,$bannerMarkup);
	$bannerMarkup = str_replace('$newWindow',$newWindow,$bannerMarkup);
	$bannerMarkup = str_replace('$buttonLabel',$buttonLabel,$bannerMarkup);
	$bannerMarkup = str_replace('$editLink',$editLink,$bannerMarkup);
	//:: Images: $bannerImage = image-title-text-link
	$bannerMarkup = str_replace('$bannerImageUrl',$bannerImageUrl,$bannerMarkup);
	$bannerMarkup = str_replace('$bannerImageAlt',$bannerImageAlt,$bannerMarkup);
	$bannerMarkup = str_replace('$bannerImageTitle',$bannerImageTitle,$bannerMarkup);
	$bannerMarkup = str_replace('$bannerImageHeight',$bannerImageHeight,$bannerMarkup);
	$bannerMarkup = str_replace('$bannerImageWidth',$bannerImageWidth,$bannerMarkup);

  
?>

<?php print $bannerMarkup; ?>

