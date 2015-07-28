<?php

  $title = $view->get_title();

?>



<section class="showcase__content" id="showcase">
  <header class="showcase__header">
    <a href="<?php print url('<front>') ; ?>" title="<?php print t('Home'); ?>" rel="home" id="logo">
      <img src="<?php print theme_get_setting('logo') ?>" alt="<?php print t('Home'); ?>" />
    </a>
    <div class="showcase__header_content">
      <?php print render($title_prefix); ?>
      <?php if ($title): ?>
        <h1 class="title" id="page-title"><?php print $title; ?></h1>
      <?php endif; ?>
      <?php print render($title_suffix); ?>
      
      <?php if ($header): ?>
        <div class="showcase__view_header">
          <?php print $header; ?>
        </div>
      <?php endif; ?>
      
      <?php if ($pager): ?>
        <?php print $pager; ?>
      <?php endif; ?>
    </div>
  </header>
  
  <?php if ($rows): ?>
    <div class="showcase__main_content">
      <?php print $rows; ?>
    </div>
  <?php elseif ($empty): ?>
    <div class="showcase__main_content--empty">
      <?php print $empty; ?>
    </div>
  <?php endif; ?>

  <div class="showcase__submit">
    <a href="/about-showcase" class="showcase__submit_link btn">Submit Your Showcase</a>
  </div>

  <?php if ($footer): ?>
    <footer class="view-footer">
      <?php print $footer; ?>
    </footer>
  <?php endif; ?>

</section>
