<?php

/**
 * @file
 * This template is used to print a single field in a view.
 *
 * It is not actually used in default Views, as this is registered as a theme
 * function which has better performance. For single overrides, the template is
 * perfectly okay.
 *
 * Variables available:
 * - $view: The view object
 * - $field: The field handler object that can process the input
 * - $row: The raw SQL result that can be used
 * - $output: The processed output that will normally be used.
 *
 * When fetching output from the $row, this construct should be used:
 * $data = $row->{$field->field_alias}
 *
 * The above will guarantee that you'll always get the correct data,
 * regardless of any changes in the aliasing that might happen if
 * the view is modified.
 */
?>
<?php #print $output; ?>

<div class="showcase__images">
  <?php print $row->field_field_showcase_images[0]['rendered']; ?>
</div>
  
<?php # Social icons ?>
<?php $current_page = url('node/' . $row->nid, array('absolute' => TRUE)); ?>

<section class="showcase__social_sharing">

  <p class="showcase_social_sharing__label">Share</p>

  <ul class="showcase_social_sharing__list">
    <li class="showcase_social_sharing__item mail">
      <i class="social_icon__icon">
        <a class="social_icon__link icon-mail" href="mailto:?&subject=NEDCamp+Showcase&body=<?php print urlencode($current_page); ?>" rel="external">
          <span class="social_icon__text">Share via E-mail</span>
        </a>
      </i>
    </li>

    <li class="showcase_social_sharing__item facebook">
      <i class="social_icon__icon">
        <a class="social_icon__link icon-facebook" href="https://www.facebook.com/sharer/sharer.php?u=<?php print urlencode($current_page); ?>" rel="external">
          <span class="social_icon__text">Share on Facebook</span>
        </a>
      </i>
    </li>

    <li class="showcase_social_sharing__item googleplus">
      <i class="social_icon__icon">
        <a class="social_icon__link icon-googleplus" href="https://plus.google.com/share?url=<?php print urlencode($current_page); ?>" rel="external">
          <span class="social_icon__text">Share on Google+</span>
        </a>
      </i>
    </li>
    
    <li class="showcase_social_sharing__item twitter">
      <i class="social_icon__icon">
        <a class="social_icon__link icon-twitter" href="https://twitter.com/intent/tweet?via=nedcamp&hashtags=nedcamp&url=<?php print urlencode($current_page); ?>" rel="external">
          <span class="social_icon__text">Share on Twitter</span>
        </a>
      </i>
    </li>

  </ul>
</section>