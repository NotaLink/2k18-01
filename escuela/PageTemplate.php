<?php
abstract class PageTemplate {
	abstract protected function printHeader();
	abstract protected function printFooter();
	abstract protected function printMenu();
	abstract protected function printBody();
	
	protected $title = 'PageTemplate';
	protected $author = 'PageAuthor';
	
	public function printPage() {
		$text = "<html>";
		$text .= $this->printHeader();
		
		$text .= "<body>";
				$text .= "<div id='menu'>";
					$text .= $this->printMenu();
				$text .= "</div>";
				$text .= "<div id='main'>";
					$text .= $this->printBody();
				$text .= "</div>";
		
				$text .= "<div id = 'footer'>";
					$text .= $this->printFooter();
				$text .= "</div>";
		$text .= "</body>";
		
		$text .= "</html>";
		echo $text;
	}
	
}
?>
